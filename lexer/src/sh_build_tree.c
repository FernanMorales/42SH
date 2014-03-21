/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_build_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:31:27 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/19 17:06:57 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Grammar:
**
** cmd_line := [ seq_cmd ]*
**
** seq_cmd := log_cmd [ ; cmd_line ]*
**
** log_op := '||' | '&&'
**
** log_cmd := pipe_cmd [ log_op log_cmd ]*
**
** pipe_cmd := cmd [ | pipe_cmd ]*
**
** redir_op := << | < | > | >>
**
** redir := redir_op string
**
** cmd := [ redir ]* string [ string | redir ]*
*/
t_ckbt_node	*sh_new_node_pipe(t_ckbt *tree)
{
	t_sh_command	cmd;

	cmd.type = SH_COMMAND_TYPE_PIPE;
	cmd.commands = NULL;
	cmd.argv = NULL;
	cmd.in = NULL;
	cmd.in_is_heredoc = 0;
	cmd.out = NULL;
	cmd.out_append = 0;
	return (ckbt_new_node(tree, &cmd));
}

t_ckbt_node	*sh_new_node_semicolon(t_ckbt *tree)
{
	t_sh_command	cmd;

	cmd.type = SH_COMMAND_TYPE_SEMICOLON;
	cmd.commands = NULL;
	cmd.argv = NULL;
	cmd.in = NULL;
	cmd.in_is_heredoc = 0;
	cmd.out = NULL;
	cmd.out_append = 0;
	return (ckbt_new_node(tree, &cmd));
}

t_ckbt_node	*sh_new_node_logic(t_ckbt *tree, t_sh_token_type type)
{
	t_sh_command	cmd;

	if (type == SH_TOKEN_TYPE_LOGICAL_AND)
		cmd.type = SH_COMMAND_TYPE_AND;
	else
		cmd.type = SH_COMMAND_TYPE_OR;
	cmd.commands = NULL;
	cmd.argv = NULL;
	cmd.in = NULL;
	cmd.in_is_heredoc = 0;
	cmd.out = NULL;
	cmd.out_append = 0;
	return (ckbt_new_node(tree, &cmd));
}

t_ckbt_node	*sh_new_node_string(t_ckbt *tree)
{
	t_sh_command	cmd;

	cmd.type = SH_COMMAND_TYPE_EXEC;
	cmd.commands = NULL;
	cmd.argv = ckl_new(t_cks);
	cmd.in = NULL;
	cmd.in_is_heredoc = 0;
	cmd.out = NULL;
	cmd.out_append = 0;
	return (ckbt_new_node(tree, &cmd));
}

int			sh_has_redirection(t_ckl *tokens)
{
	t_am_token	*tok1;
	t_am_token	*tok2;

	if (tokens->first == NULL || tokens->first->next == NULL)
		return (0);
	tok1 = &ckl_data(t_am_token, tokens->first);
	tok2 = &ckl_data(t_am_token, tokens->first->next);
	return ((tok1->type == SH_TOKEN_TYPE_REDIR_IN
			|| tok1->type == SH_TOKEN_TYPE_HERE_DOC
			|| tok1->type == SH_TOKEN_TYPE_REDIR_OUT
			|| tok1->type == SH_TOKEN_TYPE_APPEND_REDIR_OUT)
		&& (tok2->type == SH_TOKEN_TYPE_STRING
			|| tok2->type == SH_TOKEN_TYPE_QUOTE_STRING));
}

int			sh_has_arg(t_ckl *tokens)
{
	t_am_token	*tok;

	if (tokens->first == NULL)
		return (0);
	tok = &ckl_data(t_am_token, tokens->first);
	return (tok->type == SH_TOKEN_TYPE_STRING
		|| tok->type == SH_TOKEN_TYPE_QUOTE_STRING);
}

int			sh_parse_redirection(t_ckl *tokens, t_sh_command *cmd)
{
	t_am_token	*tok;
	t_am_token	*arg;

	tok = &ckl_data(t_am_token, tokens->first);
	arg = &ckl_data(t_am_token, tokens->first->next);
	if (tok->type == SH_TOKEN_TYPE_REDIR_IN
		|| tok->type == SH_TOKEN_TYPE_HERE_DOC)
	{
		cmd->in = arg->value_computed;
		cmd->in_is_heredoc = tok->type == SH_TOKEN_TYPE_HERE_DOC;
	}
	if (tok->type == SH_TOKEN_TYPE_REDIR_OUT
		|| tok->type == SH_TOKEN_TYPE_APPEND_REDIR_OUT)
	{
		cmd->out = arg->value_computed;
		cmd->out_append = tok->type == SH_TOKEN_TYPE_APPEND_REDIR_OUT;
	}
	ckl_withdraw(tokens, tokens->first);
	ckl_withdraw(tokens, tokens->first);
	return (0);
}

int			sh_parse_arg(t_ckl *tokens, t_sh_command *cmd)
{
	t_am_token	*tok;

	tok = &ckl_data(t_am_token, tokens->first);
	ckl_append(cmd->argv, &tok->value_computed);
	ckl_withdraw(tokens, tokens->first);
	return (0);
}

int			sh_parse_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	t_sh_command	*cmd;

	*root = NULL;
	if (tokens->first == NULL)
		return (-1);
	*root = sh_new_node_string(tree);
	cmd = &ckbt_data(t_sh_command, *root);
	while (sh_has_redirection(tokens))
		sh_parse_redirection(tokens, cmd);
	while (sh_has_redirection(tokens) || sh_has_arg(tokens))
	{
		if (sh_has_redirection(tokens))
			sh_parse_redirection(tokens, cmd);
		else
			sh_parse_arg(tokens, cmd);
	}
	if (cmd->argv->length == 0)
		return (-1);
	return (tokens->length != 0);
}

int			sh_parse_pipe_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	t_am_token		*tok;
	t_ckbt_node		*node;
	int				error;

	if (tokens->first == NULL)
		return (-1);
	node = NULL;
	if ((error = sh_parse_cmd(tokens, tree, &node)) == 1)
	{
		if (tokens->first == NULL)
		{
			*root = node;
			return (0);
		}
		tok = &ckl_data(t_am_token, tokens->first);
		if (tok->type != SH_TOKEN_TYPE_PIPE)
		{
			*root = node;
			return (1);
		}
		*root = sh_new_node_pipe(tree);
		(*root)->left = node;
		ckl_withdraw(tokens, tokens->first);
		return (sh_parse_pipe_cmd(tokens, tree, &(*root)->right));
	}
	*root = node;
	return (error);
}

unsigned	sh_parse_num_log_ops(t_ckl *tokens)
{
	t_ckl_item		*item;
	t_am_token		*tok;
	unsigned		num;

	num = 0;
	item = tokens->first;
	while (item)
	{
		tok = &ckl_data(t_am_token, item);
		if (tok->type == SH_TOKEN_TYPE_SEMICOLON)
			return (num);
		if (tok->type == SH_TOKEN_TYPE_LOGICAL_AND
			|| tok->type == SH_TOKEN_TYPE_LOGICAL_OR)
			num++;
		item = item->next;
	}
	return (num);
}

int			sh_parse_actual_log_cmd(t_ckl *tokens, t_ckbt *tree,
				t_ckbt_node **root, unsigned num_ops)
{
	t_sh_command		cmd;
	t_sh_command		*cmdp;
	t_ckbt_node			*node;
	t_am_token			*tok;
	int					error;

	if (tokens->first == NULL)
		return (-1);
	if (num_ops == 0)
		return (sh_parse_pipe_cmd(tokens, tree, root));
	cmd.type = -1;
	cmd.argv = NULL;
	*root = node = ckbt_new_node(tree, &cmd);
	cmdp = &ckbt_data(t_sh_command, node);
	if ((error = sh_parse_actual_log_cmd(tokens, tree, &node->left, num_ops - 1)) == 1)
	{
		if (tokens->first == NULL)
			return (1);
		tok = &ckl_data(t_am_token, tokens->first);
		if (tok->type == SH_TOKEN_TYPE_LOGICAL_AND)
			cmdp->type = SH_COMMAND_TYPE_AND;
		else if (tok->type == SH_TOKEN_TYPE_LOGICAL_OR)
			cmdp->type = SH_COMMAND_TYPE_OR;
		ckl_withdraw(tokens, tokens->first);
		return (sh_parse_pipe_cmd(tokens, tree, &node->right));
	}
	return (error);
}

int			sh_parse_log_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	if (tokens->first == NULL)
		return (-1);
	return (sh_parse_actual_log_cmd(tokens, tree, root,
		sh_parse_num_log_ops(tokens)));
}

int			sh_parse_seq_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	t_am_token		*tok;
	t_ckbt_node		*node;
	int				error;

	if (tokens->first == NULL)
		return (-1);
	node = NULL;
	if ((error = sh_parse_log_cmd(tokens, tree, &node)) == 1)
	{
		if (tokens->first == NULL)
		{
			*root = node;
			return (0);
		}
		tok = &ckl_data(t_am_token, tokens->first);
		if (tok->type != SH_TOKEN_TYPE_SEMICOLON)
		{
			*root = node;
			return (1);
		}
		*root = sh_new_node_semicolon(tree);
		(*root)->left = node;
		ckl_withdraw(tokens, tokens->first);
		return (sh_parse_cmd_line(tokens, tree, &(*root)->right));
	}
	*root = node;
	return (error);
}

int			sh_parse_cmd_line(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	if (tokens->first == NULL)
		return (0);
	return (sh_parse_seq_cmd(tokens, tree, root));
}

void		sh_group_pipe_subcommands_do(t_ckbt_node *root, t_ckl *cmds)
{
	t_sh_command		*cmd;

	if (root)
	{
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_EXEC)
			ckl_append(cmds, cmd);
		else if (cmd->type == SH_COMMAND_TYPE_PIPE)
		{
			sh_group_pipe_subcommands_do(root->left, cmds);
			sh_group_pipe_subcommands_do(root->right, cmds);
		}
	}
}

void		sh_group_pipe_subcommands(t_ckbt_node *root)
{
	t_sh_command		*cmd;

	if (root)
	{
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_PIPE)
		{
			cmd->commands = ckl_new(t_sh_command);
			sh_group_pipe_subcommands_do(root->left, cmd->commands);
			sh_group_pipe_subcommands_do(root->right, cmd->commands);
			root->left = NULL;
			root->right = NULL;
		}
		else
		{
			sh_group_pipe_subcommands(root->left);
			sh_group_pipe_subcommands(root->right);
		}
	}
}

int			sh_build_tree(t_ckl *tokens, t_ckbt *tree)
{
	int		error;

	if ((error = sh_parse_cmd_line(tokens, tree, &tree->root)))
		return (error);
	sh_group_pipe_subcommands(tree->root);
	return (0);
}

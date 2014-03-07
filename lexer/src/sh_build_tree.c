/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_build_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:31:27 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/07 03:19:48 by ckleines         ###   ########.fr       */
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
** cmd := string [ string ]*
*/

t_ckbt_node	*sh_new_node_pipe(t_ckbt *tree)
{
	t_sh_command	cmd;

	cmd.type = SH_COMMAND_TYPE_PIPE;
	cmd.argv = NULL;
	return (ckbt_new_node(tree, &cmd));
}

t_ckbt_node	*sh_new_node_semicolon(t_ckbt *tree)
{
	t_sh_command	cmd;

	cmd.type = SH_COMMAND_TYPE_SEMICOLON;
	cmd.argv = NULL;
	return (ckbt_new_node(tree, &cmd));
}

t_ckbt_node	*sh_new_node_logic(t_ckbt *tree, t_sh_token_type type)
{
	t_sh_command	cmd;

	if (type == SH_TOKEN_TYPE_LOGICAL_AND)
		cmd.type = SH_COMMAND_TYPE_AND;
	else
		cmd.type = SH_COMMAND_TYPE_OR;
	cmd.argv = NULL;
	return (ckbt_new_node(tree, &cmd));
}

t_ckbt_node	*sh_new_node_string(t_ckbt *tree)
{
	t_sh_command	cmd;

	cmd.type = SH_COMMAND_TYPE_EXEC;
	cmd.argv = ckl_new(t_am_token);
	return (ckbt_new_node(tree, &cmd));
}

int			sh_parse_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	t_am_token		*tok;
	t_sh_command	*cmd;

	*root = NULL;
	if (tokens->first == NULL)
		return (1);
	tok = &ckl_data(t_am_token, tokens->first);
	if (tok->type != SH_TOKEN_TYPE_STRING && tok->type != SH_TOKEN_TYPE_QUOTE_STRING)
		return (1);
	*root = sh_new_node_string(tree);
	cmd = &ckbt_data(t_sh_command, *root);
	while (tokens->first != NULL)
	{
		tok = &ckl_data(t_am_token, tokens->first);
		if (tok->type != SH_TOKEN_TYPE_STRING && tok->type != SH_TOKEN_TYPE_QUOTE_STRING)
			return (1);
		ckl_append(cmd->argv, tok);
		ckl_withdraw(tokens, tokens->first);
	}
	return (0);
}

int			sh_parse_pipe_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	t_am_token		*tok;
	t_ckbt_node		*node;

	if (tokens->first == NULL)
		return (1);
	node = NULL;
	if (sh_parse_cmd(tokens, tree, &node) == 1)
	{
		if (tokens->first == NULL)
			return (0);
		tok = &ckl_data(t_am_token, tokens->first);
		if (tok->type != SH_TOKEN_TYPE_PIPE)
			return (1);
		*root = sh_new_node_pipe(tree);
		(*root)->left = node;
		ckl_withdraw(tokens, tokens->first);
		return (sh_parse_pipe_cmd(tokens, tree, &(*root)->right));
	}
	*root = node;
	return (0);
}

int			sh_parse_log_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	t_am_token		*tok;
	t_ckbt_node		*node;

	if (tokens->first == NULL)
		return (1);
	node = NULL;
	if (sh_parse_pipe_cmd(tokens, tree, &node) == 1)
	{
		if (tokens->first == NULL)
			return (0);
		tok = &ckl_data(t_am_token, tokens->first);
		if (tok->type != SH_TOKEN_TYPE_LOGICAL_AND
			&& tok->type != SH_TOKEN_TYPE_LOGICAL_OR)
			return (1);
		*root = sh_new_node_logic(tree, tok->type);
		(*root)->left = node;
		ckl_withdraw(tokens, tokens->first);
		return (sh_parse_log_cmd(tokens, tree, &(*root)->right));
	}
	*root = node;
	return (0);
}

int			sh_parse_seq_cmd(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	t_am_token		*tok;
	t_ckbt_node		*node;

	if (tokens->first == NULL)
		return (1);
	node = NULL;
	if (sh_parse_log_cmd(tokens, tree, &node) == 1)
	{
		if (tokens->first == NULL)
			return (0);
		tok = &ckl_data(t_am_token, tokens->first);
		if (tok->type != SH_TOKEN_TYPE_SEMICOLON)
			return (1);
		*root = sh_new_node_semicolon(tree);
		(*root)->left = node;
		ckl_withdraw(tokens, tokens->first);
		return (sh_parse_cmd_line(tokens, tree, &(*root)->right));
	}
	*root = node;
	return (0);
}

int			sh_parse_cmd_line(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	if (tokens->first == NULL)
		return (0);
	return (sh_parse_seq_cmd(tokens, tree, root));
}

int			sh_build_tree(t_ckl *tokens, t_ckbt *tree)
{
	return (sh_parse_cmd_line(tokens, tree, &tree->root));
}

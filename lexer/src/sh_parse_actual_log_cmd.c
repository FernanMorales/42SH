#include "sh.h"

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
	error = sh_parse_actual_log_cmd(tokens, tree, &node->left, num_ops - 1);
	if (error == 1)
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

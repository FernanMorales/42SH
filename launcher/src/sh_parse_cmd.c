#include "sh.h"

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

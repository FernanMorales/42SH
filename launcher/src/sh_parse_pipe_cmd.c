#include "sh.h"

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
			return ((*root = node), 0);
		tok = &ckl_data(t_am_token, tokens->first);
		if (tok->type != SH_TOKEN_TYPE_PIPE)
			return ((*root = node), 1);
		*root = sh_new_node_pipe(tree);
		(*root)->left = node;
		ckl_withdraw(tokens, tokens->first);
		return (sh_parse_pipe_cmd(tokens, tree, &(*root)->right));
	}
	*root = node;
	return (error);
}

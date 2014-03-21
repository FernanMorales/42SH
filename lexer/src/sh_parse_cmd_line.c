#include "sh.h"

int			sh_parse_cmd_line(t_ckl *tokens, t_ckbt *tree, t_ckbt_node **root)
{
	if (tokens->first == NULL)
		return (0);
	return (sh_parse_seq_cmd(tokens, tree, root));
}

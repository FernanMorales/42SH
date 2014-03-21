#include "sh.h"

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

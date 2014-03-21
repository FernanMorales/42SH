#include "sh42.h"

int		sh_exec_pipe(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root)
{
	t_sh_command		*cmd;

	if (root)
	{
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_EXEC)
		{
			return (sh_exec_cmd(env, cmd));
		}
		else if (cmd->type == SH_COMMAND_TYPE_PIPE && cmd->commands)
		{
			return (sh_exec_pipe_routine(env, cmd));
		}
		return (3);
	}
	return (1);
	(void)tree;
}

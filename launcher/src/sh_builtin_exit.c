#include "sh42.h"

int		sh_builtin_exit(t_sh_env *env, t_sh_command *cmd)
{
	int		exit_code;

	exit_code = 0;
	if (!cmd->argv || !cmd->argv->first)
		return (1);
	if (cmd->argv->first->next)
		if (ckstd_atoi(ckl_data(t_cks, cmd->argv->first->next), &exit_code))
		{
			return (1);
		}
	exit(exit_code);
	return (0);
	(void)env;
}

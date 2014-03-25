#include "sh42.h"

int		sh_builtin_setenv(t_sh_env *env, t_sh_command *cmd)
{
	const char		*usage;

	if (!cmd->argv || !cmd->argv->first)
		return (1);
	if (!cmd->argv->first->next || !cmd->argv->first->next->next)
	{
		usage = "setenv: usage: setenv key value\n";
		write(2, usage, ckstd_strlen(usage));
		return (1);
	}
	ms_setenv(
		ckl_data(t_cks, cmd->argv->first->next),
		ckl_data(t_cks, cmd->argv->first->next->next),
		1
	);
	return (0);
	(void)env;
}

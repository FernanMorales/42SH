#include "sh42.h"

int		sh_builtin_unsetenv(t_sh_env *env, t_sh_command *cmd)
{
	const char		*usage;

	if (!cmd->argv || !cmd->argv->first)
		return (1);
	if (!cmd->argv->first->next)
	{
		usage = "unsetenv: usage: unsetenv key\n";
		write(2, usage, ckstd_strlen(usage));
		return (1);
	}
	ms_unsetenv(ckl_data(t_cks, cmd->argv->first->next));
	return (0);
	(void)env;
}

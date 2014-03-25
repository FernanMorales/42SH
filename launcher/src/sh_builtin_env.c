#include "sh42.h"

int		sh_builtin_env(t_sh_env *env, t_sh_command *cmd)
{
	ms_environ_print(environ);
	return (0);
	(void)env;
	(void)cmd;
}

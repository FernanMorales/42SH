#include "sh42.h"

int		sh_init_env(t_sh_env *env, int argc, const char **argv)
{
	const char	*tty;

	if (argc < 1 || argv == NULL || argv[0] == NULL)
		return (1);
	if ((tty = ttyname(0)) == NULL
		|| (env->tty_fd = open(tty, O_WRONLY) == -1))
		return (1);
	if (sh_init_env_get_base(argv[0], &env->base))
		return (1);
	env->last_ret = 0;
	return (0);
}

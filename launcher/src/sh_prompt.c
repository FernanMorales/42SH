#include "sh42.h"

void	sh_prompt(t_sh_env *env)
{
	const char	*user;
	const char	*pwd;

	user = ms_getenv("USER");
	pwd = ms_getenv("PWD");
	write(env->tty_fd, "[ ", 2);
	if (user)
		write(env->tty_fd, user, ckstd_strlen(user));
	if (user && pwd)
		write(env->tty_fd, ":", 1);
	if (pwd)
		write(env->tty_fd, pwd, ckstd_strlen(pwd));
	write(env->tty_fd, " ] $> ", 6);
}

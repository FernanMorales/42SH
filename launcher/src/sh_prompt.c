#include "sh42.h"

void	sh_prompt(void)
{
	const char	*user;
	const char	*pwd;

	user = ms_getenv("USER");
	pwd = ms_getenv("PWD");
	write(1, "[ ", 2);
	if (user)
		write(1, user, ckstd_strlen(user));
	if (user && pwd)
		write(1, ":", 1);
	if (pwd)
		write(1, pwd, ckstd_strlen(pwd));
	write(1, " ] $> ", 6);
}

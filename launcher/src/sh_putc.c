#include "sh42.h"

int			sh_putc(int c)
{
	write(g_sh_env->tty_fd, &c, 1);
	return (0);
}

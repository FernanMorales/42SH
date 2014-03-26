#include "sh42.h"

t_cks		sh_read_line(t_sh_env *env)
{
	int		status;
	int		key;

	tputs(tgetstr("vi", NULL), 0, sh_putc);
	tcsetattr(0, TCSADRAIN, &env->term_new);
	sh_prompt(env);
	while ((status = read(env->tty_fd, env->buf, SH_COMMAND_BUF_SIZE - 1)) > 0)
	{
		env->buf[status] = '\0';
		key = sh_get_key(env->buf);
		if (key == SH_KEY_NEWLINE || key == SH_KEY_EOT)
			break ;
		// execute what's necessary for the current key
	}
	// here get line
	tcsetattr(0, TCSADRAIN, &env->term_orig);
	tputs(tgetstr("ve", NULL), 0, sh_putc);
	return (NULL);
}

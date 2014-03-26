#include "sh42.h"

void		sh_print_line(t_sh_env *env, int print_cursor)
{
	t_ckl_item	*it;

	tputs(tgetstr("dl", NULL), 0, sh_putc);
	tputs(tgetstr("al", NULL), 0, sh_putc);
	tputs(tgetstr("cr", NULL), 0, sh_putc);
	sh_prompt(env);
	it = env->char_list->first;
	print_cursor = 0;
}

t_cks		sh_read_line(t_sh_env *env)
{
	int		status;
	int		key;

	if ((env->char_list = ckl_new(char)) == NULL)
		return (NULL);
	tputs(tgetstr("vi", NULL), 0, sh_putc);
	tcsetattr(0, TCSADRAIN, &env->term_new);
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

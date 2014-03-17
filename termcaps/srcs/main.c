
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include "ft_term.h"
#include "libft.h"

t_env		g_e;

void		init_env(t_env *e, char **envp)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (envp[i])
		i++;
	if ((e->env_c = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		return ;
	while (++j < i)
		e->env_c[j] = ft_strdup(envp[j]);
	e->env_c[j] = NULL; //ft_strnew(0);
}

int			press_key(t_lst *l, char *buf)
{
	char							*cur_key;
	extern const t_mov_functions	g_mov_functions[];
	size_t							i;

	i = 0;
	while ((cur_key = g_mov_functions[i].key) != NULL)
	{
		if (ft_memcmp(buf, cur_key, 8) == 0)
		{
			g_mov_functions[i].funct(l);
			return (1);
		}
		i++;
	}
	return (0);
}

/* void		insert_char_to_list(t_lst *l, char *buf) */
/* { */

/* 	if (l->cur->size_lst == 1) */
/* 	{ */
/* 		insert_cur_top(l, buf); */
/* 	} */
/* 	else */
/* 	{ */
/* 		insert_cur_position(l, l->cur->cursor, buf); */
/* 	} */
/* 	print_lst(l->cur); */
/* } */
void		insert_char_to_list(t_lst *l, char *buf)
{
	if (l->size_lst == 1)
	{
		insert_top(l, buf[0]);
	}
	else
	{
		insert_pos(l, l->cursor, buf[0]);
	}
	print_lst(l);
}

int		main(int ac, char **av, char **envp)
{
	char	buf[8];
	int		ret;
	extern t_env	g_e;
	t_lst	*l;

	(void)av;
	l = init_list();
	init_env(&g_e, envp);
	init_term(&g_e);
	if (ac != 1)
		return (1);
	print_prompt();
	while ((ret = read(0, buf, 8)) != 0)
	{
		if (press_key(l, buf) == 0)
			insert_char_to_list(l, buf);
		buf[0] = 0;
		buf[1] = 0;
		buf[2] = 0;
		buf[3] = 0;
		buf[4] = 0;
		buf[5] = 0;
		buf[6] = 0;
		buf[7] = 0;
	}
	ft_print(g_e.env_c);
	close_term(&g_e);
	return (0);
}

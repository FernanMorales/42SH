
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
	e->env_c[j] = NULL;
}
/* work on it*/
t_lst		clear_lst(t_lst *l)
{
	t_elem	*tmp;

	tmp = l->first;
	while (tmp != l->last)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
}
/*  */
int			press_key(t_lst_histo *histo, t_lst *l, char *buf)
{
	char							*cur_key;
	extern const t_mov_functions	g_mov_functions[];
	size_t							i;

	i = 0;
	while ((cur_key = g_mov_functions[i].key) != NULL)
	{
		if (ft_memcmp(buf, K_RETURN, 8) == 0)
		{
			save_in_string(l, histo);
			l = clear_lst(l);
			return (2);
		}
		else if (ft_memcmp(buf, cur_key, 8) == 0)
		{
			g_mov_functions[i].funct(l, histo);
			return (1);
		}
		i++;
	}
	return (0);
}

void		insert_char_to_list(t_lst *l, char *buf)
{
	if (l->size_lst == 1 || l->cursor == l->first)
	{
		insert_top(l, buf[0]);
	}
	else
	{
		insert_pos(l, l->cursor, buf[0]);
	}
	print_lst(l);
}

char	*buffer(void)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * 8);
	ft_bzero(buf, 8);
	return (buf);
}

void			commande(t_lst *l, t_lst_histo *histo)
{
	char		*buf;
	int			ret;
	int			i;
	extern t_env	g_e;

	buf = buffer();
	print_lst(l);
	while ((ret = read(0, buf, 8)) != 0)
	{
//		printf("%o %o %o %o %o %o %o %o\n", buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);
		if ((i = press_key(histo, l, buf)) == 0)
			insert_char_to_list(l, buf);
		else if (i == 2)
		{
			add_histo(histo, l);
			return ;
		}
		buf = buffer();
	}
	ft_print(g_e.env_c);
}

int		main(int ac, char **av, char **envp)
{
	extern t_env	g_e;
	t_lst_histo		*histo;
	t_lst	*l;

	(void)av;
	init_env(&g_e, envp);
	init_term(&g_e);
	l = init_list();
	histo = (t_lst_histo *)malloc(sizeof(t_lst_histo));
	histo->first = NULL;
	histo->last = NULL;
	if (ac != 1)
		return (1);
	while (42)
	{
		print_prompt();
		commande(l, histo);
	}
	close_term(&g_e);
	return (0);
}

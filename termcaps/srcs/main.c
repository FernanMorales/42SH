
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

void	commande(t_lst_histo *histo)
{
	char	buf[8];
	int		ret;
	int		i;
	t_lst	*l;
	extern t_env	g_e;

	l = init_list();
	print_lst(l);
	/*if (histo->first != NULL)
	{
		print_lst(histo->first->his);
	}*/
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
}

int		main(int ac, char **av, char **envp)
{
	extern t_env	g_e;
	t_lst_histo		*histo;

	(void)av;
	init_env(&g_e, envp);
	init_term(&g_e);
	histo = (t_lst_histo *)malloc(sizeof(t_lst_histo));
	histo->first = NULL;
	histo->last = NULL;
	if (ac != 1)
		return (1);
	while (42)
	{
		print_prompt();
		commande(histo);
	}
	close_term(&g_e);
	return (0);
}

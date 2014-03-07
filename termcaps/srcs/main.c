/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:35:37 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/07 19:16:04 by dtortera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* pour check les signal */
/*
void		check_handler(int sig)
{
	signal(SIGINT, signal_handler);
}
*/

/* check entrer */
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

void		insert_char_to_list(t_lst *l, char *buf)
{
	if (l->cur->size_lst == 0)
	{
		insert_empty_lst(l->cur, buf);
		l->cur->cursor = l->cur->first;
	}
	else
	{
		insert_elem(l->cur, buf);
		//	l->cur->cursor = l->cur->cursor->next;
	}
	printf("{%s}\n", l->cur->cursor->data);
}

int		main(int ac, char **av, char **envp)
{
	char	buf[128];
	int		ret;
	extern t_env	g_e;
	t_lst	*l;

//	e = (t_env *)malloc(sizeof(t_env));
	l = (t_lst *)malloc(sizeof(t_lst));
	init_list(l);
	init_env(&g_e, envp);
	init_term(&g_e);
	if (ac != 1)
		return (1);
	printf("%s\n", av[0]);
	while ((ret = read(0, buf, 8)) != 0)
	{
		//buf[ret] = '\0';
		printf("[%o %o %o %o %o %o %o %o]\n",
			   buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
		if (press_key(l, buf) == 0)
		{
			insert_char_to_list(l, buf);
		}
		ft_putstr("avant clear\n");
		//l->cursor = l->last;
		buf[0] = 0;
		buf[1] = 0;
		buf[2] = 0;
		buf[3] = 0;
		buf[4] = 0;
		buf[5] = 0;
		buf[6] = 0;
		buf[7] = 0;

		cur_print(l->cur);
	}
	ft_print(g_e.env_c);
	close_term(&g_e);
	return (0);
}

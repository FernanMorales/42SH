/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:35:37 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/04 19:52:03 by pvarin           ###   ########.fr       */
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

int			tputs_putchar(int c)
{
	extern t_env	g_e;

	write(g_e.fd_tty, &c, 1);
	return (1);
}

void		ft_print(char **line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		ft_putstr(line[i]);
		ft_putchar('\n');
		i++;
	}
}

void		rest_cursor(int len)
{
	while (len > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		len--;
	}
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
}

void		cur_print(t_lst *l)//, t_env *e)
{
	extern t_env	g_e;
	t_elem	*tmp;
	int		i;

	i = -1;
	tmp = l->first;
	rest_cursor(l->size_lst);
	while (++i < l->size_lst)
	{
		ft_putstr_fd(tmp->data, g_e.fd_tty);
		tmp = tmp->next;
	}
}

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
void		press_key(char *buf)
{
	ft_putstr("press key");
	if (ft_memcmp(buf, K_DEL_L, 8) == 0)
		ft_putstr("\n{delete}\n");
}

int		main(int ac, char **av, char **envp)
{
	char	buf[8];
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
	while ((ret = read(0, buf, 1)) != 0)
	{
		buf[ret] = '\0';
		printf("[%o %o %o %o %o %o %o %o]\n",
			   buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
		press_key(buf);
		if (l->size_lst == 0)
			insert_empty_lst(l, buf);
		else
			insert_elem(l, buf);
		cur_print(l);
	}
	ft_print(g_e.env_c);
	close_term(&g_e);
	return (0);
}

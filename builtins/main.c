/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:45:26 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/27 21:50:17 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ftsh.h"

extern char	**environ;

static void	start_counters(t_env *e, char **environ)
{
	if (!*environ)
		exit(3);
	e->i = 0;
	e->j = 0;
	e->k = 0;
	e->l = 0;
	e->status = 0;
	e->father = 0;
	e->process = -1;
	e->lst = NULL;
	e->env = copy_env(e->env, environ);
	while (ft_strstr(e->env[e->i], "PATH") == NULL)
		e->i++;
	while (ft_strstr(e->env[e->j], "PWD") == NULL)
		e->j++;
	while (ft_strstr(e->env[e->k], "OLDPWD") == NULL)
		e->k++;
	while (ft_strstr(e->env[e->l], "HOME") == NULL)
		e->l++;
	e->lib = ft_strsplit(e->env[e->i], ':');
	print_header();
}

int			main(void)
{
	t_env	e;

	start_counters(&e, environ);
	while (++e.process <= 28)
	{
		e.father = fork();
		if (e.father == 0)
		{
			stock_cmd(&e.lst, e.data, &e.father, e);
            if (ft_strcmp("exit", e.lst->content[0]) == 0)
            {
                ft_putendl("CACA");
                e.father = 1;
                exit(0);
            }
			while (e.lst != NULL)
			{
				if (check_builtin(e.lst->content, e.father))
					treat_case(e.lst->content, &e);
				else
					exec_cmd(&e, e.lst->content);
				e.lst = e.lst->next;
			}
		}
		else
			if ((waitpid(e.father, &e.status, 0) != e.father))
				e.process = 0;
	}
	return (e.status);
}

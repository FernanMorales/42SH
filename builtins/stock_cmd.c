/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 21:19:47 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/27 21:49:37 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ftsh.h"

void		free_tab(char **tab)
{
	int	i;

	i = count_str(tab);
	while (tab[i])
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char		**copy_env(char **env, char **environ)
{
	int		i;

	i = 0;
	env = (char **)malloc(sizeof(char *) * count_str(environ) + 1);
	while (environ[i] != NULL)
	{
		env[i] = environ[i];
		i++;
	}
	return (env);
}

int			check_builtin(char **var, pid_t father)
{
	if (ft_strcmp("exit", var[0]) == 0)
    {
        father = 0;
        exit(0);
    }
	if (ft_strcmp("cd", var[0]) == 0\
			|| ft_strcmp("env", var[0]) == 0\
			|| ft_strcmp("setenv", var[0]) == 0 \
			|| ft_strcmp("unsetenv", var[0]) == 0)
		return (1);
	return (0);
}

void		addnode(t_list **s, char **name)
{
	if (*s == NULL)
	{
		*s = (t_list *)malloc(sizeof(t_list));
		(*s)->content = copy_env((*s)->content, name);
		(*s)->next = NULL;
	}
	else
		addnode(&((*s)->next), name);
}

int			stock_cmd(t_list **s, char *data, pid_t *father, t_env e)
{
	int		i;
	char	**str;
	char	**str2;

	str = NULL;
	str2 = NULL;
	print_prompt(e);
	i = get_next_line(0, &data);
	if (i == 0)
		kill(*father, SIGQUIT);
	str = ft_strsplit(data, ';');
	i = 0;
	while (str[i])
	{
		str2 = ft_strsplit(str[i], ' ');
		addnode(s, str2);
		free_tab(str2);
		++i;
	}
	return (1);
}

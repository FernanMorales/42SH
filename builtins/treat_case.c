/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 01:05:09 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/26 00:56:45 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ftsh.h"

static int			test_rights(char *var)
{
	struct stat		filestat;

	if (stat(var, &filestat) < 0)
		return (0);
	if (S_ISDIR(filestat.st_mode) != 1)
		return (2);
    printf("RESULT = %d\n", filestat.st_mode);
	if (filestat.st_mode < 16448)
		return (1);
	else
		return (0);
}

static void			change_oldpwd(char **env, char *buf)
{
	*env = ft_strjoin("OLD", buf);
}

static void			change_pwd(char **env)
{
	char			cwd[1024];

	*env = ft_strjoin("PWD=", getcwd(cwd, sizeof(cwd)));
}

static int			cd_case(char **var)
{
	if (test_rights(var[1]) == 2)
	{
		print_cderror(var[1], 1);
		return (0);
	}
	else if (test_rights(var[1]) == 1)
	{
		print_cderror(var[1], 2);
		return (0);
	}
	if (var[2] != NULL)
	{
		print_cderror(var[1], 3);
		return (0);
	}
	if (chdir(var[1]) == -1)
	{
		print_cderror(var[1], 4);
		return (0);
	}
	return (1);
}

void				treat_case(char **var, t_env *e)
{
	e->home = ft_strsub(e->env[e->l], 5, ft_strlen(e->env[e->l]) - 5);
	if (ft_strcmp("cd", var[0]) == 0)
	{
		if (!var[1])
		{
			e->test = ft_strsplit(ft_strjoin("cd ", e->home), ' ');
			treat_case(e->test, e);
			return ;
		}
		if (ft_strcmp(var[1], "~") == 0)
			var[1] = ft_strsub(e->env[e->l], 5, ft_strlen(e->env[e->l]) - 5);
		e->m = cd_case(var);
		if (e->m == 1)
		{
			change_oldpwd(&e->env[e->k], e->env[e->j]);
			change_pwd(&e->env[e->j]);
		}
	}
	if (ft_strcmp("env", var[0]) == 0)
		print_env(e->env);
	if (ft_strcmp("setenv", var[0]) == 0)
		set_env(e, var);
	if (ft_strcmp("unsetenv", var[0]) == 0)
		unset_env(e, var);
}

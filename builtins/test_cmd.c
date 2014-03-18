/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 01:17:37 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/26 21:43:10 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftsh.h"

static char	*exec_file(char *cmd)
{
	char	*cut;

	cut = ft_strsub(cmd, 1, ft_strlen(cmd) - 1);
	if (access(cut, F_OK) == -1)
	{
		ft_putstr("ft_minishell1: no such file or directory: ");
		ft_putendl(cut);
	}
	return (cut);
}

char		*test_cmd(char **lib, char *var, int i)
{
	char	*cmd;
	char	*test;
	char	**path;

	i = -1;
	test = ft_strdup(var + 1);
	if (access(test, F_OK) != -1)
		return (test);
	path = ft_strsplit(lib[i + 1], '=');
	cmd = ft_strjoin(path[1], var);
	if (ft_strstr(var, "./") != NULL)
		return (exec_file(var));
	while (access(cmd, F_OK) == -1 && lib[++i] != NULL)
		cmd = ft_strjoin(lib[i], var);
	if (access(cmd, F_OK) == -1 && lib[i] == NULL)
	{
		ft_putstr("ft_minishell1: command not found: ");
		write(2, ft_strsub(var, 1, ft_strlen(var) - 1), \
				ft_strlen(var) - 1);
		write(1, "\n", 1);
		return (NULL);
	}
	return (cmd);
}

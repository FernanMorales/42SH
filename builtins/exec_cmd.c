/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 20:17:14 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/26 21:53:53 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ftsh.h"

void		start_child(char **av, int *fds, t_env *e)
{
	char	*cmd;
	char	*cmd1;
	char	**str;

	str = trim(av);
	cmd = ft_strjoin("/", str[0]);
	cmd1 = test_cmd(e->lib, cmd, e->i);
	dup2(fds[1], 1);
	close(fds[0]);
	execve(cmd1, str, e->env);
}

void		start_father(char **av, int *fds, t_env *e)
{
	char	*cmd;
	char	*cmd1;
	char	**str;

	str = trim2(av);
	cmd = ft_strjoin("/", str[0]);
	cmd1 = test_cmd(e->lib, cmd, e->i);
	dup2(fds[0], 0);
	close(fds[1]);
	execve(cmd1, str, e->env);
}

void		treat_pipe(t_env *e, char **str)
{
	pid_t	child;
	int		status;
	int		fds[2];

	pipe(fds);
	status = 0;
	child = fork();
	if (child == -1)
		kill(child, SIGINT);
	if (child == 0)
		start_child(str, fds, e);
	else
	{
		wait(&status);
		start_father(str, fds, e);
	}
	dup2(0, fds[0]);
	close(fds[0]);
	dup2(1, fds[1]);
	close(fds[1]);
	exit(1);
}

void		exec_cmd(t_env *e, char **content)
{
	pid_t	son;
	int		status;
	char	**str;

	son = fork();
	status = 0;
	str = NULL;
	if (son == 0)
	{
		str = copy_env(str, content);
		if (check_pipe(str) == 1)
			treat_pipe(e, str);
		else
		{
			e->cmd1 = ft_strjoin("/", str[0]);
			e->cmd = test_cmd(e->lib, e->cmd1, e->i);
			execve(e->cmd, str, e->env);
		}
	}
	else
		if (waitpid(son, &status, 0) != son)
			status = -1;
}

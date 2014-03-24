/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_pipe_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:21:04 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:21:05 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void	st_dup(pid_t pid, int fd_next[2], t_sh_command *c)
{
	if (pid == 0)
	{
		dup2(fd_next[0], 0);
		sh_dup(c);
		close(fd_next[0]);
		close(fd_next[1]);
		sh_execve(c);
	}
	if (pid > 0)
	{
		dup2(fd_next[1], 1);
		close(fd_next[1]);
		close(fd_next[0]);
	}
}

void	st_exec(t_ckl *commands, int *last_pid, t_sh_env *env)
{
	int				fd_next[2] = { 0, 1 };
	t_ckl_item		*item;
	t_sh_command	*c;
	pid_t			pid;

	item = commands->last;
	while (item)
	{
		c = &ckl_data(t_sh_command, item);
		sh_preprocess_cmd(env, c);
		sh_heredoc(c);
		if (pipe(fd_next) != -1 && (pid = fork()) != -1)
		{
			if (item == commands->last)
				*last_pid = pid;
			st_dup(pid, fd_next, c);
		}
		item = item->prev;
	}
}

void	st_wait(int last_pid, t_sh_env *env)
{
	int		stat;
	pid_t	pid;

	env->last_ret = 0;
	while ((pid = wait(&stat)) != -1)
	{
		if (pid == last_pid)
			env->last_ret = (WIFEXITED(stat)) ? WEXITSTATUS(stat) : 1;
	}
}

int		sh_exec_pipe_routine(t_sh_env *env, t_sh_command *cmd)
{
	pid_t			last_pid;
	int				stat;

	if (fork() == 0)
	{
		last_pid = -1;
		st_exec(cmd->commands, &last_pid, env);
		st_wait(last_pid, env);
		exit(env->last_ret);
	}
	if (wait(&stat) != -1)
		env->last_ret = (WIFEXITED(stat)) ? WEXITSTATUS(stat) : 1;
	return (0);
}

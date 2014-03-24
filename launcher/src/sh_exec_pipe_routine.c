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

int		sh_exec_pipe_routine(t_sh_env *env, t_sh_command *cmd)
{
	int				fd_next[2] = { 0, 1 };
	t_ckl_item		*item;
	t_sh_command	*c;
	pid_t			pid;

	if (fork() == 0)
	{
		item = cmd->commands->last;
		while (item)
		{
			c = &ckl_data(t_sh_command, item);
			sh_heredoc(c);
			if (pipe(fd_next) != -1 && (pid = fork()) != -1)
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
			item = item->prev;
		}
		while (wait(NULL) != -1)
			;
		exit(1);
	}
	wait(NULL);
	return (0);
	(void)env;
	(void)cmd;
}

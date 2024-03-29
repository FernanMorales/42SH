/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:22:14 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:22:14 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int				sh_exec_cmd(t_sh_env *env, t_sh_command *cmd)
{
	pid_t			pid;
	int				stat;
	t_sh_builtin	*builtin;

	if (sh_preprocess_cmd(env, cmd))
		return (1);
	if ((builtin = sh_cmd_to_builtin(cmd)) != NULL && builtin->func != NULL)
		return ((env->last_ret = builtin->func(env, cmd)));
	pid = fork();
	if (pid == 0)
	{
		sh_heredoc(cmd);
		sh_dup(cmd);
		sh_execve(cmd);
	}
	else if (pid > 0)
	{
		if (waitpid(pid, &stat, 0) != -1)
			env->last_ret = (WIFEXITED(stat)) ? WEXITSTATUS(stat) : 1;
	}
	return (0);
}

#include "sh42.h"

/*
** format: arg [arg]*
** where arg is a string
*/
int		sh_exec_cmd(t_sh_env *env, t_sh_command *cmd)
{
	pid_t		pid;
	int			stat;

	pid = fork();
	if (pid == 0)
	{
		sh_heredoc(cmd);
		sh_dup(cmd);
		sh_execve(cmd);
	}
	else if (pid > 0)
	{
		waitpid(pid, &stat, 0);
		env->last_ret = (WIFEXITED(stat)) ? WEXITSTATUS(stat) : 1;
	}
	return (0);
}

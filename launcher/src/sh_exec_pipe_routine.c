#include "sh42.h"

int		sh_exec_pipe_routine(t_sh_env *env, t_sh_command *cmd)
{
	int				fd_next[2] = { 0, 1 };
	int				write;
	t_ckl_item		*item;
	t_sh_command	*c;
	pid_t			pid;
	t_ckl			*processes;
	t_sh_process	p;

	if (fork() == 0)
	{
		processes = ckl_new(t_sh_process);
		item = cmd->commands->last;
		write = 1;
		while (item)
		{
			c = &ckl_data(t_sh_command, item);
			dprintf(2, "forking %s\n", ckl_data(t_cks, c->argv->first));
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
					p.pid = pid;
					p.cmd = c;
					ckl_append(processes, &p);
				}
			}
			else
				dprintf(2, "pipe or fork error\n");
			item = item->prev;
		}
		close(write);
		close(fd_next[1]);
		close(fd_next[0]);
		while (wait(NULL) != -1)
			;
		exit(1);
	}
	wait(NULL);
	return (0);
	(void)env;
	(void)cmd;
}

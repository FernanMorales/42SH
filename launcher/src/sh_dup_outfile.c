#include "sh42.h"

int		sh_dup_outfile(t_sh_command *cmd)
{
	int		fd;

	if (!cmd->out)
		return (0);
	if ((fd = open(cmd->out, O_WRONLY | O_CREAT
		| ((cmd->out_append) ? O_APPEND : O_TRUNC), 0777)) != -1)
	{
		close(1);
		dup2(fd, 1);
	}
	return (1);
}

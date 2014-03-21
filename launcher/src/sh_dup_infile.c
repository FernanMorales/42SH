#include "sh42.h"

int		sh_dup_infile(t_sh_command *cmd)
{
	int		fd;

	if (cmd->in == NULL || cmd->in_is_heredoc == 1)
		return (0);
	fd = open(cmd->in, O_RDONLY);
	if (fd != -1)
	{
		dup2(fd, 0);
		return (0);
	}
	return (1);
}

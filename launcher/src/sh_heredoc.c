#include "sh42.h"

int		sh_heredoc(t_sh_command *cmd)
{
	t_cks		line;
	int			has_stop;
	int			fd;

	if (cmd->in == NULL || cmd->in_is_heredoc == 0)
		return (1);
	fd = open("/tmp/42sh-heredoc", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd != -1)
	{
		has_stop = 0;
		while ((line = cks_get_line(0)) != NULL)
		{
			if (cks_cmp_len(cmd->in, line, cks_len(line)) == 0)
			{
				has_stop = 1;
				break ;
			}
			write(fd, line, cks_len(line));
			write(fd, "\n", 1);
		}
		cmd->heredoc_success = has_stop;
		return (0);
	}
	return (1);
}

#include "sh42.h"

int		sh_dup(t_sh_command *cmd)
{
	sh_dup_heredoc(cmd);
	sh_dup_infile(cmd);
	sh_dup_outfile(cmd);
	return (0);
}

#include "sh42.h"

t_sh_builtin	*sh_cmd_to_builtin(t_sh_command *cmd)
{
	t_cks		prog;
	size_t		i;

	prog = ckl_data(t_cks, cmd->argv->first);
	i = 0;
	while (sh_builtin[i].name != NULL)
	{
		if (cks_cmp(prog, sh_builtin[i].name) == 0)
			return (&sh_builtin[i]);
		i++;
	}
	return (NULL);
}

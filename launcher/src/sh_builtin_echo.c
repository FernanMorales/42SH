#include "sh42.h"

int		sh_builtin_echo(t_sh_env *env, t_sh_command *cmd)
{
	t_ckl_item	*item;
	int			nl;

	if (!cmd->argv || !cmd->argv->first)
		return (1);
	item = cmd->argv->first->next;
	nl = item && cks_cmp(ckl_data(t_cks, item), "-n") == 0;
	if (nl)
		item = item->next;
	while (item)
	{
		write(1, ckl_data(t_cks, item), cks_len(ckl_data(t_cks, item)));
		if (item->next)
			write(1, " ", 1);
		item = item->next;
	}
	if (!nl)
		write(1, "\n", 1);
	return (0);
	(void)env;
}

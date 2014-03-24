#include "sh42.h"

int		sh_preprocess_cmd(t_sh_env *env, t_sh_command *cmd)
{
	t_ckl_item		*item;
	t_cks			*arg;
	t_cks			ns;
	const char		*home;

	if (cmd->argv == NULL)
		return (2);
	item = cmd->argv->first;
	while (item)
	{
		arg = &ckl_data(t_cks, item);
		if ((*arg)[0] == '~' && (*arg)[1] == '/')
		{
			if ((home = getenv("HOME")) == NULL)
				return (1);
			ns = cks_sub(*arg, 1);
			cks_free(*arg);
			ns = cks_prepend(ns, home);
			*arg = ns;
		}
		item = item->next;
	}
	return (0);
	env = NULL;
}

#include "sh42.h"

int		sh_builtin_env(t_sh_env *env, t_sh_command *cmd)
{
	t_ckl_item		*item;
	char			*pos;

	if (!cmd->argv || !cmd->argv->first)
		return (1);
	if (fork() == 0)
	{
		item = cmd->argv->first->next;
		if (item)
		{
			if (cks_cmp(ckl_data(t_cks, cmd->argv->first->next), "-i") == 0)
			{
				ms_environ_clear();
				item = item->next;
			}
			while (item)
			{
				if ((pos = ckstd_strchr(ckl_data(t_cks, item), '-')))
				{
					
				}
				item = item->next;
			}
		}
		ms_environ_print(environ);
		exit(0);
	}
	wait(NULL);
	return (0);
	(void)env;
	(void)cmd;
}

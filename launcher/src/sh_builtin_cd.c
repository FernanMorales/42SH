#include "sh42.h"

int			sh_builtin_cd(t_sh_env *env, t_sh_command *cmd)
{
	t_cks		arg;
	t_ckl_item	*item;

	if (cmd->argv == NULL)
		return (1);
	// get the `follow` option value
	item = cmd->argv->first;
	while (item)
	{
		arg = ckl_data(t_cks, item);
		if (arg[0] == '-' && arg[1] && arg[1] != '-')
		{
			
			item = item->next;
			continue ;
		}
		break ;
	}
	// remove the arg '--' if it is present
	if (item)
	{
		arg = ckl_data(t_cks, item);
		if (cks_cmp(arg, "--") == 0)
			item = item->next;
	}
	// get the new directory
	arg = (item) ? ckl_data(t_cks, item) : NULL;
	if (arg == NULL)
		// go home
	else
		// go to arg
	env = NULL;
	cmd = NULL;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <ckleines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:39:00 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:39:02 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		sh_builtin_env(t_sh_env *env, t_sh_command *cmd)
{
	t_ckl_item		*item;

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
		}
		ms_environ_print(environ);
		exit(0);
	}
	wait(NULL);
	return (0);
	(void)env;
}

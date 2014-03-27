/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_unsetenv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <ckleines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:39:14 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:39:15 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		sh_builtin_unsetenv(t_sh_env *env, t_sh_command *cmd)
{
	const char		*usage;

	if (!cmd->argv || !cmd->argv->first)
		return (1);
	if (!cmd->argv->first->next)
	{
		usage = "unsetenv: usage: unsetenv key\n";
		write(2, usage, ckstd_strlen(usage));
		return (1);
	}
	ms_unsetenv(ckl_data(t_cks, cmd->argv->first->next));
	return (0);
	(void)env;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_preprocess_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <ckleines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:37:47 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:37:49 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		st_preprocess_home(t_sh_env *env, t_cks *arg)
{
	const char		*home;
	t_cks			ns;

	if ((*arg)[0] == '~' && ((*arg)[1] == '/' || !(*arg)[1]))
	{
		if ((home = ms_getenv("HOME")) == NULL)
			return (1);
		ns = cks_sub(*arg, 1);
		cks_free(*arg);
		ns = cks_prepend(ns, home);
		*arg = ns;
	}
	return (0);
	env = NULL;
}

void	st_remove_backslashes(t_cks *arg)
{
	t_cks		ns;
	t_cks		that;

	that = *arg;
	ns = cks_new("");
	while (*that)
	{
		if (*that == '\\' && *(that + 1))
		{
			ns = cks_append_len(ns, that + 1, 1);
			that += 2;
		}
		else if (*that != '\\')
			ns = cks_append_len(ns, that++, 1);
		else
			that++;
	}
	cks_free(*arg);
	*arg = ns;
}

int		sh_preprocess_cmd(t_sh_env *env, t_sh_command *cmd)
{
	t_ckl_item		*item;
	t_cks			*arg;

	if (cmd->argv == NULL)
		return (2);
	item = cmd->argv->first;
	while (item)
	{
		arg = &ckl_data(t_cks, item);
		if (st_preprocess_home(env, arg))
			return (1);
		st_remove_backslashes(arg);
		item = item->next;
	}
	return (0);
}

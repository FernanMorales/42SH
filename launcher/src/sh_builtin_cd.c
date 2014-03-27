/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <ckleines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:38:38 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:56:26 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void		st_remove_double_dash(t_ckl_item **item)
{
	t_ckl_item		*i;
	t_cks			arg;

	i = *item;
	if (i)
	{
		arg = ckl_data(t_cks, i);
		if (cks_cmp(arg, "--") == 0)
			i = i->next;
	}
	*item = i;
}

int			st_follow(t_ckl_item **item)
{
	t_ckl_item		*i;
	t_cks			arg;
	int				follow;
	size_t			j;

	follow = 1;
	i = *item;
	while (i && follow != -1)
	{
		arg = ckl_data(t_cks, i);
		if (arg[0] == '-' && arg[1] && arg[1] != '-' && (j = 1))
		{
			while (arg[j])
			{
				if (arg[j] != 'P' && arg[j] != 'L')
					return (-1);
				follow = (arg[j++] == 'P') ? 0 : 1;
			}
			i = i->next;
			continue ;
		}
		break ;
	}
	*item = i;
	return (follow);
}

void		st_set_new_cwd(t_cks cwd, t_cks arg, int follow)
{
	char		*ncwd;

	if (follow && arg[0] != '/')
	{
		cwd = cks_append(cwd, "/");
		cwd = cks_append(cwd, arg);
		ms_setenv("PWD", cwd, 1);
		write(1, cwd, ckstd_strlen(cwd));
	}
	else
	{
		ncwd = getcwd(NULL, 0);
		ms_setenv("PWD", ncwd, 1);
		write(1, ncwd, ckstd_strlen(ncwd));
		free(ncwd);
	}
	write(1, "\n", 1);
	cks_free(arg);
	cks_free(cwd);
}

int			st_change_dir(t_cks dir, int follow)
{
	char		*cwd;
	t_cks		d;

	if (dir == NULL)
		return (1);
	if (cks_cmp(dir, "-") == 0)
		dir = cks_new(ms_getenv("OLDPWD"));
	if (dir == NULL)
		return (1);
	d = NULL;
	if ((cwd = getcwd(NULL, 0))
	&& (d = cks_new(cwd)) && chdir(dir) != -1)
	{
		ms_setenv("OLDPWD", ms_getenv("PWD"), 1);
		st_set_new_cwd(d, dir, follow);
		free(cwd);
		return (0);
	}
	free(cwd);
	cks_free(d);
	return (1);
}

int			sh_builtin_cd(t_sh_env *env, t_sh_command *cmd)
{
	t_ckl_item	*item;
	int			follow;

	if (cmd->argv == NULL || cmd->argv->first == NULL)
		return (1);
	item = cmd->argv->first->next;
	follow = st_follow(&item);
	if (follow == -1)
		return (1);
	st_remove_double_dash(&item);
	return (st_change_dir((item) ? ckl_data(t_cks, item)
	: cks_new(ms_getenv("HOME")), follow));
	(void)env;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:20:54 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:21:43 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		sh_init_env(t_sh_env *env, int argc, const char **argv)
{
	const char	*tty;

	if (argc < 1 || argv == NULL || argv[0] == NULL)
		return (1);
	if ((tty = ttyname(0)) == NULL
		|| (env->tty_fd = open(tty, O_WRONLY) == -1))
		return (1);
	ms_environ_copy();
	if (environ == NULL)
		return (1);
	env->last_ret = 0;
	return (0);
}

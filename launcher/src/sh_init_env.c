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
	const char	*term;

	if (argc < 1 || argv == NULL || argv[0] == NULL)
		return (1);
	if ((environ = ms_environ_clone()) == NULL
		|| (term = ms_getenv("TERM")) == NULL
		|| tgetent(NULL, term) <= 0
		|| tcgetattr(0, &env->term_orig) == -1
		|| tcgetattr(0, &env->term_new) == -1
		|| (env->tty_fd = open(ttyname(0), O_RDWR)) == -1
		|| (env->buf = (char *)malloc(SH_COMMAND_BUF_SIZE)) == NULL
		|| (env->history = ckl_new(t_ckl *)) == NULL
		|| (env->char_list = ckl_new(char)) == NULL)
		return (1);
	env->last_ret = 0;
	env->cursor = 0;
	return (0);
}

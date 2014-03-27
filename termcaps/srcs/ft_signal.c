/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 21:38:24 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/04 18:35:26 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include <sys/ioctl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void			handle_sigtstp(t_env *e)
{
	char			cp[2];

	cp[0] = e->term.c_cc[VSUSP];
	cp[1] = 0;
	if (isatty(1))
	{
		close_term(e);
		tcsetattr(0, 0, &e->term_origin);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cp);
	}
}

static void			handle_sigcont(t_env *e)
{
	signal(SIGTSTP, signal_handler);
	init_term(e);
//	put_win(e);
}

static void			handle_sigwinch(t_env *e)
{
	ioctl(0, TIOCGWINSZ, &e->term_size);
//	put_win(e);
	//	cut_print(l); ligne modifier
}

static void			handle_close(t_env *e)
{
	close_term(e);
	exit (ESC);
}

void				signal_handler(int sig)
{
	extern t_env	g_e;

	if (sig == SIGTSTP)
		handle_sigtstp(&g_e);
	if (sig == SIGCONT)
		handle_sigcont(&g_e);
	if (sig == SIGWINCH)
		handle_sigwinch(&g_e);
	if (sig == SIGINT || sig == SIGTERM)
		handle_close(&g_e);
}


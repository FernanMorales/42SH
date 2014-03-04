/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 10:13:35 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/04 17:20:51 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>

void		init_term(t_env *e)
{
	char	*path;


//	ioctl(0, TIOCGWINSZ, &e->term_size);
	if ((path = ttyname(isatty(STDOUT_FILENO))) == NULL)
		exit (ERROR_INIT);
	if ((e->fd_tty = open(path, O_RDWR)) == -1)
		exit (ERROR_INIT);
	if (tgetent(NULL, getenv("TERM")) < 1)
		exit (ERROR_INIT);
	if (tcgetattr(0, &e->term_origin) == -1)
		exit (ERROR_INIT);
	if (tcgetattr(0, &e->term) == -1)
		exit (ERROR_INIT);
//	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	ioctl(0, TIOCGWINSZ, &e->term_size);
	e->term.c_lflag &= ~(ICANON | ECHO);
	e->term.c_lflag |= ISIG;
	e->term.c_cc[VMIN] = 1;
	tcsetattr(0, 0, &e->term);
}

void		close_term(t_env *e)
{
//	tputs(tgetstr("te", NULL), 1, tputs_putchar);
//	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	e->term.c_lflag |= ICANON | ECHO;
	if (close(e->fd_tty) == -1)
		exit (ERROR_CLOSE);
	tcsetattr(0, 0, &e->term);
}
/*
void		creat_lst(t_lst *l, char **av)
{
	int		i;

	i = 0;
	while (av[++i])
	{
		if (l->size_lst == 0)
			insert_empty_lst(l, av[i]);
		else
			insert_elem(l, av[i]);
	}
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtortera <dtortera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:47:32 by dtortera          #+#    #+#             */
/*   Updated: 2014/03/26 19:58:11 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include <stddef.h>
#include "ft_term.h"
#include "libft.h"

int			tputs_putchar(int c)
{
	extern t_env	g_e;

	write(g_e.fd_tty, &c, 1);
	return (1);
}

void		reset_cursor(int len)
{
	while (len > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		len--;
	}
}

void		print_lst(t_lst *l)
{
	extern t_env	g_e;
	t_elem	*tmp;
	int		i;

	i = -1;
	tmp = l->first;
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
	while (++i < l->size_lst)
	{
		if (tmp == l->cursor)
		{
			tputs(tgetstr("mr", NULL), 1, tputs_putchar);
			ft_putchar_fd(tmp->data, g_e.fd_tty);
			tputs(tgetstr("me", NULL), 1, tputs_putchar);
		}
		else
			ft_putchar_fd(tmp->data, g_e.fd_tty);
		tmp = tmp->next;
	}
	reset_cursor(l->size_lst);
}

/*

void		print_lst(t_lst *l)
{
	extern t_env	g_e;
	t_elem	*tmp;
	int		i;

	i = -1;
	tmp = l->first;
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
	while (++i < l->size_lst)
	{

		if (tmp == l->cursor->next)
		{
			tputs(tgetstr("mr", NULL), 1, tputs_putchar);
			ft_putstr_fd(tmp->data, g_e.fd_tty);
			tputs(tgetstr("me", NULL), 1, tputs_putchar);
		}
		else
			ft_putstr_fd(tmp->data, g_e.fd_tty);
		tmp = tmp->next;
	}
	reset_cursor(l->size_lst);

}
*/
void		print_prompt(void)
{
	extern t_env	g_e;

		ft_putstr_fd(PROMPT, g_e.fd_tty);
}

void		print_clear(size_t len)
{
	while (len > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		len--;
	}
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
}

void		ft_print(char **line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		ft_putstr(line[i]);
		ft_putchar('\n');
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtortera <dtortera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:47:32 by dtortera          #+#    #+#             */
/*   Updated: 2014/03/07 19:29:11 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include "ft_term.h"
#include "libft.h"

int			tputs_putchar(int c)
{
	extern t_env	g_e;

	write(g_e.fd_tty, &c, 1);
	return (1);
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

void		rest_cursor(int len)
{
	while (len > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		len--;
	}
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
}

void		cur_print(t_lst *l)//, t_env *e)
{
	extern t_env	g_e;
	t_elem	*tmp;
	int		i;

	i = -1;
	tmp = l->first;
	rest_cursor(l->size_lst);
	while (++i < l->size_lst)
	{
		ft_putstr_fd(tmp->data, g_e.fd_tty);
		tmp = tmp->next;
	}
}

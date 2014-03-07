/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_funct_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtortera <dtortera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:34:49 by dtortera          #+#    #+#             */
/*   Updated: 2014/03/07 19:18:48 by dtortera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_term.h"

void	del_one(t_lst *l)
{
	del_elem(l->cur, l->cur->last);
}

void	move_right(t_lst *l)
{
	l->cur->cursor = l->cur->cursor->next;
}

void	move_left(t_lst *l)
{
	l->cur->cursor = l->cur->cursor->prev;
	tputs(tgetstr("le", NULL), 1, tputs_putchar);
}

void	move_up(t_lst *l)
{
	l->cur->cursor = l->cur->cursor->prev;
	tputs(tgetstr("nd", NULL), 1, tputs_putchar);
}

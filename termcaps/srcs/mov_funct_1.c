/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_funct_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtortera <dtortera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:34:49 by dtortera          #+#    #+#             */
/*   Updated: 2014/03/15 22:19:43 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_term.h"

void	del_one(t_lst *l)
{
	if (l->size_lst == 1)
		return ;
	del_elem(l, l->cursor->prev);
	print_lst(l);
}

void	move_right(t_lst *l)
{
	if (l->cursor != l->last)
	{
		l->cursor = l->cursor->next;
		print_lst(l);
	}
}

void	move_left(t_lst *l)
{
	if (l->cursor != l->first)
	{
		l->cursor = l->cursor->prev;
		print_lst(l);
	}
}

void	move_up(t_lst *l)
{
	(void)l;
	// if (!l->histo)
	// 	return ;
	// else
	// {
	// 	l->histo->last = l->frist;
	//
	// }
}

void	move_down(t_lst *l)
{
		(void)l;
}

void	save_in_string(t_lst *l)
{
	t_elem	*tmp;
	int	i;

	i = 0;
	tmp = l->first;
	// l->histo = (t_lst **)malloc(sizeof(t_lst *));
	l->str_return = (char *)malloc(sizeof(char) * (l->size_lst + 1));
	while (i < l->size_lst)
	{
		l->str_return[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	l->str_return[i] = '\0';
}

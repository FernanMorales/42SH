/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_funct_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtortera <dtortera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:34:49 by dtortera          #+#    #+#             */
/*   Updated: 2014/03/10 19:51:55 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_term.h"


#include "libft.h"

void	del_one(t_lst *l)
{
	if (l->cur->size_lst == 1)
		return ;
	if (l->cur->cursor != NULL)
	{
		del_elem(l->cur, l->cur->cursor);
		l->cur->cursor = l->cur->cursor->prev;
		cur_print(l->cur);
	}
}

void	move_right(t_lst *l)
{
	t_elem		*tmp;

	tmp = l->cur->last;
	if (l->cur->cursor != NULL)
	{
		l->cur->cursor = l->cur->cursor->next;
		cur_print(l->cur);
	}
}

void	move_left(t_lst *l)
{
	t_elem		*tmp;

	tmp = l->cur->last;
	if (l->cur->cursor != NULL)
	{
		l->cur->cursor = l->cur->cursor->prev;
		cur_print(l->cur);
	}
}

void	move_up(t_lst *l)
{
	if (!l->cur->cursor->prev)
		l->cur->cursor = l->cur->cursor->prev;
}

void	move_down(t_lst *l)
{
	if (!l->cur->cursor->next)
		l->cur->cursor = l->cur->cursor->next;
}

void	save_in_string(t_lst *l)
{
	t_elem	*tmp;
	int	i;

	i = 0;
	tmp = l->cur->first;
	l->str_return = (char *)malloc(sizeof(char) * (l->cur->size_lst + 1));
	while (i < l->cur->size_lst)
	{
		l->str_return[i] = tmp->data[0];
		tmp = tmp->next;
	}
}

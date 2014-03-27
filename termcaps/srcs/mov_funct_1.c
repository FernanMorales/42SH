/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_funct_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtortera <dtortera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:34:49 by dtortera          #+#    #+#             */
/*   Updated: 2014/03/26 20:13:02 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h" // to delete after try
#include <term.h>
#include "ft_term.h"

void	del_one(t_lst *l, t_lst_histo *histo)
{
	(void)histo;
	if (l->size_lst == 1 || l->cursor == l->first)
		return ;
	del_elem(l, l->cursor->prev);
	print_lst(l);
}

void	move_right(t_lst *l, t_lst_histo *histo)
{
	(void)histo;
	if (l->size_lst == 1)
		return ;
	if (l->cursor != l->last)
	{
		l->cursor = l->cursor->next;
		print_lst(l);
	}
}

void	move_left(t_lst *l, t_lst_histo *histo)
{
	(void)histo;
	if (l->size_lst == 1)
		return ;
	if (l->cursor != l->first)
	{
		l->cursor = l->cursor->prev;
		print_lst(l);
	}
}

void	move_up(t_lst *l, t_lst_histo *histo)
{
	(void)l;
	if (histo->size_histo == 0)
		return ;
	if (histo->pos->next)
	{
		histo->pos = histo->pos->next;
		l = histo->pos->his;
		print_lst(l);
	}
}

void	move_down(t_lst *l, t_lst_histo *histo)
{
	(void)l;
	if (histo->size_histo == 0)
		return ;
	if (histo->pos->prev)
	{
		histo->pos = histo->pos->prev;
		l = histo->pos->his;
		print_lst(l);
	}
}

t_elem_histo		*new_his(t_lst *l)
{
	t_elem_histo	*new;

	new = (t_elem_histo *)malloc(sizeof(t_elem_histo));
	new->his = l;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	save_to_histo(t_lst *l, t_lst_histo *histo)
{
	t_elem_histo *new;

	new = new_his(l);
	if (histo->size_histo == 0)
	{
		histo->first = new;
		histo->last = new;
		histo->size_histo++;
	}
	else
	{
		new->next = histo->first;
		histo->first = new;
		histo->size_histo++;
	}
	histo->pos = new;
}

void	save_in_string(t_lst *l, t_lst_histo *histo)
{
	t_elem	*tmp;
	t_lst	*new;
	int	i;

	i = 0;
	if (l->size_lst == 0)
		return ;
	tmp = l->first;
	l->str_return = (char *)malloc(sizeof(char) * (l->size_lst + 1));
	while (i < l->size_lst)
	{
		l->str_return[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	l->str_return[i] = '\0';
	save_to_histo(l, histo);
	new = init_list();
	l = new;
	print_clear(ft_strlen(PROMPT));
}

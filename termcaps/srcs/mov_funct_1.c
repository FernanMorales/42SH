/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_funct_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtortera <dtortera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:34:49 by dtortera          #+#    #+#             */
/*   Updated: 2014/03/27 21:39:56 by pvarin           ###   ########.fr       */
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
	if (histo->pos == NULL)
	{
		l = histo->first->his;
		l->cursor = l->last->prev;
		print_lst(l);
		histo->pos = histo->first;
	}
/*
	if (histo->size_histo == 1)
	{
		l = histo->pos->his;
		print_lst(l);
	}
*/
	else if (histo->pos->next)
	{
		histo->pos = histo->pos->next;
		l->cursor = l->last->prev;
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
		l->cursor = l->last;
		print_lst(l);
	}
	else
		l = init_list();
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

void		first_cpy(t_lst *l, char c)
{
	t_elem	*cpy;

	cpy = creat_elem(c);
	l->first = cpy;
	l->last = cpy;
	l->size_lst++;
}

t_lst	*cpy_lst(t_lst *l)
{
	t_elem	*tmp;
	t_lst	*cpy;
	int		i;

	i = 0;
	tmp = l->last;
	cpy = (t_lst *)malloc(sizeof(t_lst));
	cpy->size_lst = 0;
	while (i < l->size_lst)
	{
		if (i == 0)
			first_cpy(cpy, tmp->data);
		else
			insert_top(cpy , tmp->data);
		tmp = tmp->prev;
		i++;
	}
	return (cpy);
}

void	save_to_histo(t_lst *l, t_lst_histo *histo)
{
	t_elem_histo *new;
	t_lst	*cpy;

	cpy = cpy_lst(l);
	new = new_his(cpy);
	if (histo->size_histo == 0)
	{
		histo->first = new;
		histo->last = new;
		histo->size_histo++;
	}
	else
	{
		new->next = histo->first;
		new->next->prev = new;
		histo->first = new;
		histo->size_histo++;
	}
	histo->pos = NULL;
}

void	save_in_string(t_lst *l, t_lst_histo *histo)
{
	t_elem	*tmp;
	int	i;

	i = 0;
	if (l->size_lst == 1)
	{
		print_clear(ft_strlen(PROMPT));
		return ;
	}
	tmp = l->first;
	l->str_return = (char *)malloc(sizeof(char) * (l->size_lst + 1));
	while (i < l->size_lst)
	{
		l->str_return[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	l->str_return[i] = '\0';
	save_to_histo(l , histo);
	l = init_list();
	print_clear(ft_strlen(PROMPT));
}

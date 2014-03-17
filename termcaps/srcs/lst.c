/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 20:06:17 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/15 22:29:50 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_lst		*init_list(void)
{
	t_lst	*l;
	t_elem	*new;

	l = (t_lst *)malloc(sizeof(t_lst));
	new = creat_elem(' ');
	l->first = new;
	l->last = new;
	l->cursor = new;
	l->size_lst = 1;
	return (l);
}

t_elem		*creat_elem(char data)
{
	t_elem		*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		insert_top(t_lst *l, char data)
{
	t_elem	*new;

	new = creat_elem(data);
	new->next = l->first;
	l->first->prev = new;
	l->first = new;
	l->cursor = new->next;
	l->size_lst++;
}

void		insert_pos(t_lst *l, t_elem *pos, char data)
{
	t_elem	*new;
	t_elem	*tmp;

	tmp = l->first;
	while (tmp != pos)
		tmp = tmp->next;
	new = creat_elem(data);
	new->next = tmp;
	new->prev = tmp->prev;
	new->prev->next = new;
	new->next->prev = new;
	// tmp->prev->next = new;
	// tmp->prev = new;
	l->cursor = new->next;
	l->size_lst++;
}

void		del_elem(t_lst *l, t_elem *cur)
{
	if (cur == l->first)
	{
		cur->next->prev = NULL;
		l->first = cur->next;
	}
	else
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}
	cur->prev = NULL;
	cur->next = NULL;
	free(cur);
	l->size_lst--;
}

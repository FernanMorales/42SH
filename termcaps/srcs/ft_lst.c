/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:52:28 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/01 20:28:06 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_term.h"
#include <stdlib.h>

void		init_list(t_lst *l)
{
	l->first = NULL;
	l->last = NULL;
	l->cursor = NULL;
	l->size_lst = 0;
}

int			insert_empty_lst(t_lst *l, char *data)
{
	t_elem	*new;

	if ((new = (t_elem *)malloc(sizeof(t_elem))) == NULL)
		return (-1);
	if (data == NULL)
	{
		new->data = NULL;
		new->size_data = 0;
		new->selected = 0;
	}
	else
	{
		new->data = ft_strdup(data);
		new->size_data = ft_strlen(data) + 1;
		l->max_size = new->size_data > l->max_size ?
			new->size_data : l->max_size;
		new->selected = 0;
	}
	new->next = new;
	new->prev = new;
	l->first = new;
	l->last = new;
	l->size_lst++;
	return (0);
}

int			insert_elem(t_lst *l, char *data)
{
	t_elem	*new;

	if ((new = (t_elem *)malloc(sizeof(t_elem))) == NULL)
		return (-1);
	if (data == NULL)
	{
		new->data = NULL;
		new->size_data = 0;
		new->selected = 0;
	}
	else
	{
		new->data = ft_strdup(data);
		new->size_data = ft_strlen(data) + 1;
		l->max_size = new->size_data > l->max_size ?
			new->size_data : l->max_size;
		new->selected = 0;
	}
	new->next = l->last->next;
	new->prev = l->last;
	l->last->next = new;
	l->last = new;
	l->first->prev = new;
	l->size_lst++;
	return (0);
}

void		del_elem(t_lst *l, t_elem *current)
{
	if (l->size_lst == 1)
		del_last_elem(l);
	else
	{
		if (current == l->first)
			l->first = current->next;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
		l->size_lst--;
	}
}

int			del_last_elem(t_lst *l)
{
	t_elem	*del;

	if (l->size_lst != 1)
		return (-1);
	del = l->first;
	l->first = NULL;
	l->last = NULL;
	free(del->data);
	free(del);
	l->size_lst--;
	return (0);
}


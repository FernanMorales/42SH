/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:52:14 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/05 19:34:45 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_term.h"
#include "libft.h"
#include <stdlib.h>


void		init_list(t_lst *l)
{
	l->cur = (t_lst *)malloc(sizeof(t_lst));
	l->first = NULL;
	l->last = NULL;
	l->cursor = NULL;
	l->cur->first = NULL;
	l->cur->last = NULL;
	l->cur->cursor = NULL;
	l->cur->size_lst = 0;
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
	}
	else
	{
		new->data = ft_strdup(data);
		new->size_data = ft_strlen(data) + 1;
	}
	new->next = new;
	l->cursor = new;
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
	}
	else
	{
		new->data = ft_strdup(data);
		new->size_data = ft_strlen(data) + 1;
	}
	new->next = NULL;
	new->prev = l->last;
	l->last->next = new;
	l->last = new;
	l->cursor = l->cursor->next;
	l->size_lst++;
	return (0);
}

void		del_elem(t_lst *l, t_elem *current)
{
	if (l->size_lst == 0)
		return ;
	if (l->size_lst == 1)
		del_last_elem(l);
	else
	{
		if (current == l->last)
		{
			current->prev->next = NULL;
			l->last = current->prev;
		}
		else
		{
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
		free(current);
		l->size_lst--;
		if (l->cursor->prev != NULL)
			l->cursor = l->cursor->prev;
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


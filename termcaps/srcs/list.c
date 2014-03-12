/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:52:14 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/11 14:44:07 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include "libft.h"
#include <stdlib.h>

static t_elem	*new_elem(const char *data)
{
	t_elem		*new;

	if ((new = (t_elem *)malloc(sizeof(t_elem))) == NULL)
		return (NULL);
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
	return (new);
}

int			insert_cur_position(t_lst *l, t_elem *cur, const char *data)
{
	t_elem	*new;
	t_elem	*tmp;

	tmp = l->cur->first;
	new = new_elem(data);
	while (tmp && tmp != cur)
		tmp = tmp->next;
	if (tmp != l->last)
	{
		new->prev = tmp;
		new->next = tmp->next;
		tmp->next->prev = new;
		tmp->next = new;
	}
	else
	{
		new->prev = tmp;
		tmp->next = new;
		l->last = new;
	}
	l->cur->cursor = new;
	l->cur->size_lst++;
	return (0);
}

int			insert_empty_lst(t_lst *l, char *data)
{
	t_elem	*new;

	new = new_elem(data);
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

	if ((new = new_elem(data)) == NULL)
		return (-1);
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
		if (current == l->first)
		{
			l->first = current->next;
		}
		else
		{
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
		free(current);
		l->size_lst--;
	}
}

int			del_last_elem(t_lst *l)
{
	t_elem	*del;

	if (l->size_lst != 1)
		return (-1);
	if (l == NULL)
		return (-1);
	del = l->first;

	free(del->data);
	free(del);
	l->size_lst--;
	l->first = NULL;
	l->last = NULL;
	free(l);
	l = NULL;
	return (0);
}

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

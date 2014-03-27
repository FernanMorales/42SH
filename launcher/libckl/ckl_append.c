/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckl_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:03:46 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:26:15 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckl.h"

void				ckl_append(t_ckl *list, void *data)
{
	t_ckl_item		*item;

	if (list->length == 0)
	{
		list->first = ckl_new_item(list, data);
		list->last = list->first;
		list->length = 1;
	}
	else
	{
		item = ckl_new_item(list, data);
		item->prev = list->last;
		list->last->next = item;
		list->last = item;
		list->length++;
	}
}

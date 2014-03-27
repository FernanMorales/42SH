/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckl_append_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:03:57 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:04:00 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckl.h"

void	ckl_append_item(t_ckl *list, t_ckl_item *prev, void *data)
{
	t_ckl_item		*item;

	if (prev)
	{
		item = ckl_new_item(list, data);
		item->prev = prev;
		item->next = prev->next;
		if (prev->next)
			prev->next->prev = item;
		prev->next = item;
		list->length++;
		if (list->last == prev)
			list->last = item;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckl_free_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:04:15 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:26:39 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckl.h"

void		ckl_free_items(t_ckl *list, void (*callback)(void *data))
{
	t_ckl_item		*item;
	t_ckl_item		*next;

	item = list->first;
	while (item)
	{
		next = item->next;
		if (callback != NULL)
			callback(&ckl_data(char, item));
		ckl_free_item(item);
		item = next;
	}
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
}

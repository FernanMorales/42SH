/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckl_new_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:04:21 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:26:54 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckl.h"

t_ckl_item			*ckl_new_item(t_ckl *list, void *data)
{
	t_ckl_item		*item;

	item = (t_ckl_item *)malloc(
		sizeof(t_ckl_item) + list->item_size - sizeof(void *));
	if (item == NULL)
		return (item);
	ckstd_memcpy(&item->data, data, list->item_size);
	item->prev = NULL;
	item->next = NULL;
	return (item);
}

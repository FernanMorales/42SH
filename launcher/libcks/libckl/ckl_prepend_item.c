/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckl_prepend_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:04:28 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:04:28 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckl.h"

void	ckl_prepend_item(t_ckl *list, t_ckl_item *next, void *data)
{
	t_ckl_item		*item;

	if (next)
	{
		item = ckl_new_item(list, data);
		item->next = next;
		item->prev = next->prev;
		if (next->prev)
			next->prev->next = item;
		next->prev = item;
		list->length++;
		if (list->first == next)
			list->first = item;
	}
}

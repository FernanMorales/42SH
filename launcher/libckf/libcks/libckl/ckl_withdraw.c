/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckl_withdraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:04:32 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:04:34 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckl.h"

void				ckl_withdraw(t_ckl *list, t_ckl_item *item)
{
	if (list->first == item)
		list->first = item->next;
	else
		item->prev->next = item->next;
	if (list->last == item)
		list->last = item->prev;
	else
		item->next->prev = item->prev;
	list->length--;
}

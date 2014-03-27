/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ckl_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:03:41 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:25:09 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckl.h"

t_ckl				*ckl_new_f(size_t item_size)
{
	t_ckl		*list;

	list = (t_ckl *)malloc(sizeof(t_ckl));
	if (list == NULL)
		return (NULL);
	list->length = 0;
	list->item_size = item_size;
	list->first = NULL;
	list->last = NULL;
	return (list);
}

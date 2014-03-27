/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_set_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:18:55 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:29:29 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

void					cks_set_mem(t_cks str, size_t mem)
{
	size_t		*intstr;

	if (mem > SSIZE_MAX)
		mem = SSIZE_MAX;
	intstr = (size_t *)str;
	intstr[-2] = mem;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_set_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:18:50 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:29:16 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

void					cks_set_len(t_cks str, size_t len)
{
	size_t		*intstr;

	if (len > SSIZE_MAX)
		len = SSIZE_MAX;
	intstr = (size_t *)str;
	intstr[-1] = len;
	str[len] = 0;
}

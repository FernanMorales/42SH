/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_len_grow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:18:09 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:28:20 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

size_t					cks_len_grow(size_t len)
{
	if (len > SSIZE_MAX)
		len = SSIZE_MAX;
	if (len <= 4)
		return (8);
	len |= (len >> 1);
	len |= (len >> 2);
	len |= (len >> 4);
	len |= (len >> 8);
	if (sizeof(int) >= 4)
		len |= (len >> 16);
	if (sizeof(int) >= 8)
		len |= (len >> 32);
	if ((int)(len + 1) > (int)len)
		len++;
	return ((len > SSIZE_MAX) ? SSIZE_MAX : len);
}

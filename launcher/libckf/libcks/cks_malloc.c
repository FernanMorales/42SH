/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:18:16 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:28:35 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

t_cks					cks_malloc(size_t len)
{
	char	*str;
	size_t	mem;

	if (len > SSIZE_MAX)
		len = SSIZE_MAX;
	mem = cks_len_grow(len);
	str = (char *)malloc(CKS_PADDING + mem + 1);
	if (str == NULL)
		return (NULL);
	str += CKS_PADDING;
	cks_set_mem(str, mem);
	cks_set_len(str, 0);
	return (str);
}

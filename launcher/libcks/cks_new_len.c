/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_new_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:18:37 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:28:43 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

t_cks						cks_new_len(const char *s1, size_t len)
{
	t_cks					str;

	if (s1 == NULL)
		return (NULL);
	if (len > SSIZE_MAX)
		len = SSIZE_MAX;
	str = cks_malloc(len);
	if (str == NULL)
		return (NULL);
	ckstd_memcpy(str, s1, len);
	cks_set_len(str, len);
	return (str);
}

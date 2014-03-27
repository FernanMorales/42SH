/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_insert_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 21:15:35 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:27:57 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

static t_cks	st_new_str(t_cks s1, size_t pos,
					const char *s2, size_t s2len)
{
	t_cks	new_str;
	size_t	total_len;

	total_len = cks_len(s1) + s2len;
	if (total_len > SSIZE_MAX)
		total_len = SSIZE_MAX;
	new_str = cks_malloc(total_len);
	if (new_str == NULL)
	{
		cks_free(s1);
		return (NULL);
	}
	ckstd_memcpy(new_str, s1, pos);
	ckstd_memcpy(new_str + pos, s2, s2len);
	ckstd_memcpy(new_str + pos + s2len, s1 + pos, total_len - pos - s2len);
	cks_set_len(new_str, total_len);
	cks_free(s1);
	return (new_str);
}

t_cks			cks_insert_len(t_cks s1, size_t pos, const char *s2,
					size_t s2len)
{
	size_t		total_len;

	if (s1 == NULL || s2 == NULL || pos > cks_len(s1))
		return (NULL);
	if (s2len > SSIZE_MAX)
		s2len = SSIZE_MAX;
	if (pos > SSIZE_MAX)
		pos = SSIZE_MAX;
	total_len = cks_len(s1) + s2len;
	if (total_len > SSIZE_MAX)
		total_len = SSIZE_MAX;
	if (total_len > cks_mem(s1))
		return (st_new_str(s1, pos, s2, s2len));
	ckstd_memmove(s1 + pos + s2len, s1 + pos, cks_len(s1) - pos);
	ckstd_memcpy(s1 + pos, s2, s2len);
	cks_set_len(s1, total_len);
	return (s1);
}

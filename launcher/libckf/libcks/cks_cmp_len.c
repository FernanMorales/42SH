/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_cmp_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:16:35 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:17:16 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

int							cks_cmp_len(const t_cks s1,
								const char *s2, size_t len)
{
	int		ret;
	size_t	s1_len;

	s1_len = cks_len(s1);
	if (s1_len == len)
		return (ckstd_memcmp(s1, s2, len));
	ret = ckstd_memcmp(s1, s2, s1_len > len ? len : s1_len);
	if (ret != 0)
		return (ret);
	if (s1_len > len)
		return ((unsigned char)s1[len]);
	return (-(unsigned char)s2[s1_len]);
}

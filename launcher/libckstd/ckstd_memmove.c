/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckstd_memmove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:23:38 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:23:41 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ckstd.h"

void			*ckstd_memmove(void *s1, const void *s2, size_t n)
{
	char		*s1_char;
	char		*s2_char;

	if (s1 < s2)
		return (ckstd_memcpy(s1, s2, n));
	s1_char = (char *)s1 + n;
	s2_char = (char *)s2 + n;
	while (n-- > 0)
		*(--s1_char) = *(--s2_char);
	return (s1);
}

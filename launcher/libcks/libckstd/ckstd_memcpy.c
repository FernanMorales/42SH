/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckstd_memcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:23:51 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:23:53 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ckstd_memcpy(void *s1, const void *s2, size_t n)
{
	char		*s1_char;
	char		*s2_char;

	s1_char = (char *)s1;
	s2_char = (char *)s2;
	while (n-- > 0)
		*(s1_char++) = *(s2_char++);
	return (s1);
}

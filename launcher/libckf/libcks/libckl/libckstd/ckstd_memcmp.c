/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckstd_memcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:24:09 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:24:10 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ckstd_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1c;
	char	*s2c;
	size_t	i;

	i = 0;
	s1c = (char *)s1;
	s2c = (char *)s2;
	while (i < n)
	{
		if (s1c[i] != s2c[i])
			return (((unsigned char)s1c[i]) - ((unsigned char)s2c[i]));
		++i;
	}
	return (0);
}

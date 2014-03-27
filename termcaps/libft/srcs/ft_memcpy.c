/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:36:03 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/04 10:43:16 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	if (!s1 || !s2 || !n)
		return (s1);
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (n-- > 0)
		tmp1[n] = tmp2[n];
	return (s1);
}

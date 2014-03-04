/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:08:57 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 15:39:04 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	tmp1 = s1;
	tmp2 = (char *)s2;
	i = 0;
	while (n > i)
	{
		tmp1[i] = tmp2[i];
		if (tmp2[i] == (unsigned char)c)
		{
			return (s1 + i + 1);
		}
		i++;
	}
	return (NULL);
}

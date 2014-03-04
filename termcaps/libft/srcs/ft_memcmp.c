/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:46:00 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 15:56:05 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (tmp1[i] == tmp2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)tmp1[i] - (unsigned char)tmp2[i]);
}

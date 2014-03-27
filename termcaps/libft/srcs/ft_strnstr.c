/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:14:23 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 18:20:51 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		len;

	len = ft_strlen(s2);
	i = 0;
	if (s2[i] == '\0')
		return (((char *)s1));
	while (s1[i] && (i + len) <= n)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}

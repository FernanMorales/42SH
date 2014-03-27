/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:04:59 by pvarin            #+#    #+#             */
/*   Updated: 2013/11/30 16:04:05 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last;
	char	cpy_c;

	cpy_c = (char)c;
	i = 0;
	last = -1;
	if (!s)
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == cpy_c)
			last = i;
		i++;
	}
	if (s[i] == cpy_c)
			last = i;
	if (last != -1)
		return ((char *)&s[last]);
	return (NULL);
}

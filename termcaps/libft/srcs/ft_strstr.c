/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:30:48 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 18:19:43 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s2);
	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else
			j = 0;
		if (j == len)
			return ((char *)&s1[i - j + 1]);
		i++;
	}
	return (NULL);
}

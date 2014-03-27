/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:06:17 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 16:03:05 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	save;
	size_t	buf;
	size_t	len_src;

	save = size;
	len_src = ft_strlen(src);
	buf = len_src + ft_strlen(dest);
	while (*dest && size > 0)
	{
		dest++;
		size--;
	}
	if (size == 0)
		return (save + len_src);
	while (*src && size-- > 1)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (buf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 19:16:44 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 18:21:44 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	char	*new;
	size_t	i;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	i = 0;
	new = ft_strnew(ft_strlen(tmp2));
	while (tmp2[i])
	{
		new[i] = tmp2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp1[i] = new[i];
		i++;
	}
	return (s1);
}

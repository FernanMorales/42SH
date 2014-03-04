/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:32:29 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 18:10:37 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int strat, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s || len == 0)
		return (NULL);
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[strat + i];
		i++;
	}
	return (new);
}

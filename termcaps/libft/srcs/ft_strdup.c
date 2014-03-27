/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:33:27 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 15:56:52 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	len;
	unsigned int	i;
	char			*new;

	i = 0;
	len = ft_strlen(s1);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

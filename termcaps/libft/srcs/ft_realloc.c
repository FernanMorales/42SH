/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 20:15:37 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/04 12:52:57 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	char	*new;

	if ((new = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	ft_memcpy(new, ptr, size);
	return ((void *)new);
}

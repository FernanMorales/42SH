/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:09:26 by pvarin            #+#    #+#             */
/*   Updated: 2013/11/30 15:29:31 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"


t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	new = (t_list *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		if (new->content == NULL)
			return (NULL);
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

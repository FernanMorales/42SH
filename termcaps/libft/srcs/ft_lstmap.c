/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 19:34:34 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/01 11:06:21 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*prevouis;
	t_list	*origin;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	origin = new;
	prevouis = new;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		if (new == NULL)
			return (NULL);
		prevouis->next = new;
		prevouis = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (origin);
}

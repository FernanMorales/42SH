/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 10:21:42 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/02 18:07:51 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	int		result;

	if (!s1 || !s2)
		return (0);
	result = ft_strcmp(s1, s2);
	if (result != 0)
		return (0);
	else
		return (1);
}

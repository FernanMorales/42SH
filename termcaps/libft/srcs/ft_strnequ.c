/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 10:52:24 by pvarin            #+#    #+#             */
/*   Updated: 2013/12/22 07:16:05 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		result;

	if (!s1 || !s2)
		return (0);
	result = ft_strncmp(s1, s2, n);
	if (result != 0)
		return (0);
	return (1);
}

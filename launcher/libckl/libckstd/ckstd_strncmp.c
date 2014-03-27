/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckstd_strncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:59:50 by ckleines          #+#    #+#             */
/*   Updated: 2014/01/25 19:01:11 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ckstd_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i])
	{
		if (!s2[i] || s2[i] != s1[i])
			return (s1[i] - s2[i]);
		++i;
	}
	if (i < n && s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

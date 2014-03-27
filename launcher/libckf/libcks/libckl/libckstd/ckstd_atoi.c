/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckstd_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <ckleines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:28:09 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:28:45 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckstd.h"

int		ckstd_atoi(const char *s, int *val)
{
	size_t		i;
	int			sign;

	*val = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		*val += s[i++] - '0';
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		*val *= 10;
		*val += s[i++] - '0';
	}
	*val *= sign;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_posenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 11:25:06 by ckleines          #+#    #+#             */
/*   Updated: 2014/01/26 11:27:36 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static int	static_has_key(const char *value, const char *key)
{
	size_t	len;

	len = ckstd_strlen(key);
	if (ckstd_strncmp(value, key, len) == 0
		&& ckstd_strlen(value) > len
		&& value[len] == '=')
		return (1);
	return (0);
}

int			ms_posenv(const char *key)
{
	size_t	i;

	i = 0;
	while (environ[i])
	{
		if (static_has_key(environ[i], key))
			return (i);
		i++;
	}
	return (-1);
}

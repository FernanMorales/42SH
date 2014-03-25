/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 14:53:23 by ckleines          #+#    #+#             */
/*   Updated: 2014/01/26 12:04:09 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ck.h"

extern char			**	environ;

const char			*ms_getenv(const char *key)
{
	size_t	len;
	int32_t	i;

	if (environ == NULL)
		return (NULL);
	len = ck_std_strlen(key);
	i = 0;
	while (environ[i])
	{
		if (ck_std_strncmp(key, environ[i], len) == 0
			&& ck_std_strlen(environ[i]) >= len
			&& environ[i][len] == '=')
			return (environ[i] + len + 1);
		i++;
	}
	return (NULL);
}

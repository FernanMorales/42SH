/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 11:13:40 by ckleines          #+#    #+#             */
/*   Updated: 2014/01/26 13:49:30 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"
#include "ck.h"

void	ms_unsetenv(const char *key)
{
	int32_t		i;
	int32_t		pos;
	char		**nargv;
	int32_t		len;

	if ((pos = ms_posenv(key)) != -1)
	{
		len = 0;
		while (environ[len])
			len++;
		nargv = (char **)malloc(sizeof(char *) * len);
		nargv[len - 1] = NULL;
		len = 0;
		i = 0;
		while (environ[i])
		{
			if (pos != i)
				nargv[len++] = environ[i];
			else
				free(environ[i]);
			i++;
		}
		free(environ);
		environ = nargv;
	}
}

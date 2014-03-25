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

#include "sh42.h"

void	ms_unsetenv(const char *key)
{
	size_t		i;
	size_t		pos;
	char		**nargv;
	size_t		len;

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

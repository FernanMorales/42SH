/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_environ_clone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:06:48 by ckleines          #+#    #+#             */
/*   Updated: 2014/01/26 14:18:45 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

char	**ms_environ_clone(void)
{
	size_t		len;
	size_t		i;
	char		**new_environ;

	len = 0;
	while (environ[len] != NULL)
		len++;
	new_environ = (char **)malloc(sizeof(char *) * (len + 1));
	new_environ[len] = NULL;
	i = 0;
	while (i < len)
	{
		new_environ[i] = ckstd_strdup(environ[i]);
		i++;
	}
	return (new_environ);
}

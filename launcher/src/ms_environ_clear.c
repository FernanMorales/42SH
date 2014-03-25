/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_environ_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 13:58:48 by ckleines          #+#    #+#             */
/*   Updated: 2014/01/26 13:59:07 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void		ms_environ_clear(void)
{
	size_t	i;

	i = 0;
	while (environ[i])
		free(environ[i++]);
	free(environ);
	environ = (char **)malloc(sizeof(char *));
	environ[0] = NULL;
}

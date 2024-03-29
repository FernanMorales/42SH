/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <ckleines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:39:34 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 15:05:55 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int			sh_get_key(char *buf)
{
	int		i;

	i = 0;
	while (g_sh_keys[i] != NULL)
	{
		if (ckstd_strcmp(g_sh_keys[i], buf) == 0)
			return (i);
		i++;
	}
	return (-1);
}

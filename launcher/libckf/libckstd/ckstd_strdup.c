/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckstd_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <ckleines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:27:50 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 16:28:29 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckstd.h"

char		*ckstd_strdup(const char *s)
{
	size_t	len;
	char	*ns;

	len = 0;
	while (s[len])
		len++;
	if ((ns = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	ckstd_memcpy(ns, s, len + 1);
	return (ns);
}

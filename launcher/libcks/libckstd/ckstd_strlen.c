/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckstd_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:21:51 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:22:34 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>

size_t			ckstd_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && len < SSIZE_MAX)
		len++;
	return (len);
}

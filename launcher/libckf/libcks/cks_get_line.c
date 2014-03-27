/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_get_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:17:36 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/19 11:04:45 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

t_cks						cks_get_line(int fd)
{
	t_cks		s;
	char		c;
	int			ret;

	s = NULL;
	while ((ret = read(fd, &c, 1)) == 1 && c != '\n')
	{
		if (s == NULL)
			s = cks_malloc(256);
		if (s == NULL)
			return (NULL);
		s = cks_append_len(s, &c, 1);
	}
	if (s == NULL && ret == 1 && c == '\n')
		s = cks_new("");
	return (s);
}

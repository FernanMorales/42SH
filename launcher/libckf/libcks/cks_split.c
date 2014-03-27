/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 13:32:26 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/18 14:30:31 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"
#include "ckl.h"
#include <stdio.h>

static size_t	st_word_len(t_cks s, const char *del, size_t del_len)
{
	size_t		i;

	i = 0;
	while (i < cks_len(s))
	{
		if (i + del_len < cks_len(s)
			&& ckstd_memcmp(s + i, del, del_len) == 0)
			return (i);
		i++;
	}
	return (i);
}

static int		st_do_split(t_ckl *parts, const char *s,
					const char *del, int ign)
{
	size_t		word_len;
	size_t		del_len;
	t_cks		part;
	t_cks		str;
	t_cks		tmp;

	ign++;
	word_len = 0;
	str = cks_new(s);
	del_len = ckstd_strlen(del);
	while (cks_len(str) > 0)
	{
		word_len = st_word_len(str, del, del_len);
		part = cks_sub_len(str, 0, word_len);
		ckl_append(parts, &part);
		tmp = str;
		str = cks_sub(str, word_len
			+ ((cks_len(str) > word_len) ? del_len : 0));
		cks_free(tmp);
	}
	return (0);
}

t_ckl			*cks_split(const char *s, const char *del, int ignore_empty)
{
	t_ckl	*parts;

	if (s == NULL || del == NULL || (parts = ckl_new(t_cks)) == NULL)
		return (NULL);
	if (st_do_split(parts, s, del, ignore_empty))
	{
		ckl_free_items(parts, (void (*)(void *))cks_free);
		ckl_free(parts);
		return (NULL);
	}
	return (parts);
}

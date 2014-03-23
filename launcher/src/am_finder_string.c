/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_finder_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:25:00 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:25:01 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

int		am_finder_string(t_am *am, t_cks str)
{
	t_cks	sub;
	size_t	len;

	len = cks_len(str);
	if (cks_len(am->source) >= len)
	{
		sub = cks_sub_len(am->source, 0, len);
		if (cks_cmp_len(sub, str, len) == 0)
		{
			am_add_token(am, sub, NULL);
			return (1);
		}
		cks_free(sub);
	}
	return (0);
}

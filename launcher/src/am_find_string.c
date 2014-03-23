/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_find_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:24:53 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:24:54 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_find_string(t_am *am, t_am_meta meta, char *str)
{
	t_am_finder		finder;

	finder.token_type = meta.type;
	finder.type = AM_FINDER_TYPE_STRING;
	finder.join = 0;
	finder.state_prev = meta.from;
	finder.state_next = meta.to;
	finder.arg = cks_new(str);
	finder.callback = (void *)am_finder_string;
	ckl_append(am->finders, &finder);
}

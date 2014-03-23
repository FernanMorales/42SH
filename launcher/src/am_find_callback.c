/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_find_callback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:24:16 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:24:17 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_find_callback(t_am *am, t_am_meta meta,
			t_am_callback_finder_callback cb)
{
	t_am_finder		finder;

	finder.token_type = meta.type;
	finder.type = AM_FINDER_TYPE_CALLBACK;
	finder.join = 0;
	finder.state_prev = meta.from;
	finder.state_next = meta.to;
	finder.arg = NULL;
	finder.callback = (void *)cb;
	ckl_append(am->finders, &finder);
}

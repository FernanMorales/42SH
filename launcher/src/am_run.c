/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:23:23 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:23:24 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_run(t_am *am)
{
	t_ckl_item	*item;
	t_am_finder	*finder;
	int			ret;

	am_reset(am);
	am->tokens = ckl_new(t_am_token);
	if (am->tokens != NULL && (item = am->finders->first))
		while (item)
		{
			finder = &ckl_data(t_am_finder, item);
			am->curr_finder = finder;
			if (finder->state_prev == am->state_curr)
			{
				if (finder->type == AM_FINDER_TYPE_STRING)
					ret = AM_STRING(finder->callback, am, finder->arg);
				else if (finder->type == AM_FINDER_TYPE_CALLBACK)
					ret = AM_CALLBACK(finder->callback, am);
				else if (finder->type == AM_FINDER_TYPE_AUTOMATON)
					ret = AM_AUTOMATON(finder->callback, am, finder->arg,
						finder->join);
				if (ret == 1)
					am->state_curr = finder->state_next;
			}
			item = item->next;
		}
}

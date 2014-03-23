/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_free_finder_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:23:50 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:23:51 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_free_finder_content(void *f)
{
	t_am_finder	*finder;

	finder = f;
	if (finder->type == AM_FINDER_TYPE_STRING)
		cks_free(finder->arg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:23:37 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:23:38 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

t_am	*am_new(const int state_final)
{
	t_am		*am;

	am = (t_am *)malloc(sizeof(t_am));
	if (am == NULL)
		return (am);
	*(int *)&am->state_final = state_final;
	am->finders = ckl_new(t_am_finder);
	if (am->finders == NULL)
	{
		free(am);
		return (NULL);
	}
	am_reset(am);
	return (am);
}

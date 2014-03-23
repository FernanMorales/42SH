/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_find_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:23:55 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:23:56 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_find_whitespace(t_am *am, t_am_meta meta)
{
	meta.join = 1;
	am_find_automaton(am, meta, am_make_whitespace_automaton);
}

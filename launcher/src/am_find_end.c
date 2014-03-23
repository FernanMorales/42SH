/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_find_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:24:10 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:24:11 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_find_end(t_am *am, t_am_meta meta)
{
	am_find_callback(am, meta, am_callback_is_end);
}

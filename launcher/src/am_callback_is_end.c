/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_callback_is_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:23:08 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:23:09 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

int		am_callback_is_end(t_am *am)
{
	return (cks_len(am->source) == 0);
}

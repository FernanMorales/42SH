/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:16:28 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:16:31 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

int							cks_cmp(const t_cks s1, const char *s2)
{
	return (ckstd_strcmp(s1, s2));
}

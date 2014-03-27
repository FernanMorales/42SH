/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:19:02 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:19:03 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

t_cks						cks_sub(t_cks s, size_t start)
{
	t_cks		ns;

	if (start > cks_len(s))
		return (NULL);
	ns = cks_malloc(cks_len(s) - start);
	ns = cks_append_len(ns, s + start, cks_len(s) - start);
	return (ns);
}

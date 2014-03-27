/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_sub_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:19:07 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 18:44:58 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

t_cks						cks_sub_len(t_cks s, size_t start, size_t n)
{
	t_cks		ns;

	if (start + n > cks_len(s))
		return (NULL);
	ns = cks_malloc(n);
	if (ns == NULL)
		return (NULL);
	ns = cks_append_len(ns, s + start, n);
	return (ns);
}

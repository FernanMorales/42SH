/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_prepend_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:16:22 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:29:01 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

t_cks		cks_prepend_len(t_cks s1, const char *s2, size_t len)
{
	return (cks_insert_len(s1, 0, s2, len));
}

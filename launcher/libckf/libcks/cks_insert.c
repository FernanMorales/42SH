/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:15:58 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:16:01 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

t_cks			cks_insert(t_cks s1, size_t pos, const char *s2)
{
	return (cks_insert_len(s1, pos, s2, (s2 == NULL) ? 0 : ckstd_strlen(s2)));
}

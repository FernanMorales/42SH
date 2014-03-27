/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cks_append_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:16:06 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/09 10:16:07 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"

t_cks						cks_append_len(t_cks s1,
								const char *s2, size_t len)
{
	return (cks_insert_len(s1, (s1 == NULL) ? 0 : cks_len(s1), s2, len));
}

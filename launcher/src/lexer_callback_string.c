/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_callback_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:51:50 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:01:38 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

void	st_concat_next(t_cks *orig, t_cks *computed, size_t *i, t_am *am)
{
	*orig = cks_append_len(*orig, am->source + *i, 2);
	*computed = cks_append_len(*computed, am->source + *i + 1, 1);
	*i += 2;
}

void	st_concat_curr(t_cks *orig, t_cks *computed, size_t *i, t_am *am)
{
	*orig = cks_append_len(*orig, am->source + *i, 1);
	*computed = cks_append_len(*computed, am->source + *i, 1);
	(*i)++;
}

int		st_add_or_fail(t_cks orig, t_cks computed, t_am *am)
{
	if (cks_len(orig) > 0)
	{
		am_add_token(am, orig, computed);
		return (1);
	}
	cks_free(orig);
	cks_free(computed);
	return (0);
}

int		lexer_callback_string(t_am *am)
{
	size_t		i;
	t_cks		orig;
	t_cks		computed;

	orig = cks_new("");
	computed = cks_new("");
	i = 0;
	while (i < cks_len(am->source) && is_not_meaningful(am->source[i]))
	{
		if (i + 1 < cks_len(am->source) && am->source[i] == '\\')
			st_concat_next(&orig, &computed, &i, am);
		else if (am->source[i] != '\\')
			st_concat_curr(&orig, &computed, &i, am);
		else
		{
			cks_free(orig);
			cks_free(computed);
			return (0);
		}
	}
	return (st_add_or_fail(orig, computed, am));
}

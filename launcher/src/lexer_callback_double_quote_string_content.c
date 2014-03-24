/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_callback_double_quote_string_content.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:52:53 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:01:29 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

static void	st_concat_next(t_cks *orig, t_cks *computed, size_t *i, t_am *am)
{
	*orig = cks_append_len(*orig, am->source + *i, 2);
	*computed = cks_append_len(*computed, am->source + *i + 1, 1);
	*i += 2;
}

static void	st_concat_curr(t_cks *orig, t_cks *computed, size_t *i, t_am *am)
{
	*orig = cks_append_len(*orig, am->source + *i, 1);
	*computed = cks_append_len(*computed, am->source + *i, 1);
	(*i)++;
}

int			lexer_callback_double_quote_string_content(t_am *am)
{
	size_t		i;
	t_cks		orig;
	t_cks		computed;

	orig = cks_new("");
	computed = cks_new("");
	i = 0;
	while (i < cks_len(am->source) && am->source[i] != '"')
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
	am_add_token(am, orig, computed);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_callback_single_quote_string_conten          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:45:24 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/19 14:06:38 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"
#include "am.h"
#include "sh.h"

int		lexer_callback_single_quote_string_content(t_am *am)
{
	size_t		i;
	t_cks		orig;
	t_cks		computed;

	orig = cks_new("");
	computed = cks_new("");
	i = 0;
	while (i < cks_len(am->source) && am->source[i] != '\'')
	{
		if (am->source[i] == '$' || am->source[i] == '\\'
			|| am->source[i] == '"' || am->source[i] == '`'
			|| am->source[i] == '~')
		{
			orig = cks_append(orig, "\\\\\\");
			computed = cks_append(computed, "\\");
			am->source = cks_insert(am->source, i, "\\\\\\");
			i += 3;
		}
		orig = cks_append_len(orig, am->source + i, 1);
		computed = cks_append_len(computed, am->source + i, 1);
		i++;
	}
	if (cks_len(orig) > 0)
	{
		am_add_token(am, orig, computed);
		return (1);
	}
	cks_free(orig);
	cks_free(computed);
	return (0);
}

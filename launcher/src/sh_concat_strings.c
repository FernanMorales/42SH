/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_concat_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:49:33 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:09:41 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "am.h"

void	st_concat(t_ckl_item **item, t_am_token *tok, t_ckl *t)
{
	t_ckl_item	*i;
	t_am_token	*next;
	t_ckl_item	*prev;

	i = *item;
	while (i != NULL && (next = &ckl_data(t_am_token, i)) != NULL)
	{
		if (!sh_token_is_string(next))
			break ;
		if (sh_token_is_quoted_string(next))
			tok->type = SH_TOKEN_TYPE_QUOTE_STRING;
		tok->value_orig = cks_append(
			tok->value_orig, next->value_orig);
		tok->value_computed = cks_append(
			tok->value_computed, next->value_computed);
		prev = i;
		i = i->next;
		ckl_withdraw(t, prev);
	}
	*item = i;
}

void	sh_concat_strings(t_ckl *t)
{
	t_ckl_item	*i;
	t_am_token	*tok;

	i = t->first;
	while (i != NULL)
	{
		tok = &ckl_data(t_am_token, i);
		if (sh_token_is_string(tok))
		{
			if (sh_token_is_quoted_string(tok))
				tok->type = SH_TOKEN_TYPE_QUOTE_STRING;
			i = i->next;
			st_concat(&i, tok, t);
		}
		if (i != NULL)
			i = i->next;
	}
}

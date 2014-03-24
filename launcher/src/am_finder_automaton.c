/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_finder_automaton.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:24:02 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:24:03 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	st_join_tokens(t_am *am, t_am *nam, t_am_token *joined_token)
{
	t_am_token	*curr_token;
	t_ckl_item	*item;

	joined_token->value_computed = cks_new("");
	joined_token->value_orig = cks_new("");
	joined_token->type = am->curr_finder->token_type;
	item = nam->tokens->first;
	while (item)
	{
		curr_token = &ckl_data(t_am_token, item);
		joined_token->value_computed = cks_append_len(
			joined_token->value_computed,
			curr_token->value_computed,
			cks_len(curr_token->value_computed)
		);
		joined_token->value_orig = cks_append_len(
			joined_token->value_orig,
			curr_token->value_orig,
			cks_len(curr_token->value_orig)
		);
		item = item->next;
	}
	ckl_free_items(nam->tokens, am_free_token_content);
	ckl_append(nam->tokens, joined_token);
}

int		am_finder_automaton(t_am *am, t_am_maker maker)
{
	t_am		*nam;
	t_ckl_item	*item;
	t_am_token	joined_token;

	nam = maker();
	nam->source = cks_dup(am->source);
	am_run(nam);
	if (am_ok(nam))
	{
		if (am->curr_finder->join)
			st_join_tokens(am, nam, &joined_token);
		item = nam->tokens->first;
		while (item)
		{
			ckl_append(am->tokens, &ckl_data(t_am_token, item));
			item = item->next;
		}
		cks_free(am->source);
		am->source = cks_dup(nam->source);
		am_sub_free(nam);
		return (1);
	}
	am_sub_free(nam);
	return (0);
}

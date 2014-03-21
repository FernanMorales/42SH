/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 21:33:04 by ckleines          #+#    #+#             */
/*   Updated: 2014/02/28 03:56:38 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_run(t_am *am)
{
	t_ckl_item	*item;
	t_am_finder	*finder;
	int			ret;

	am_reset(am);
	am->tokens = ckl_new(t_am_token);
	if (am->tokens != NULL)
	{
		item = am->finders->first;
		while (item)
		{
			finder = &ckl_data(t_am_finder, item);
			am->curr_finder = finder;
			if (finder->state_prev == am->state_curr)
			{
				if (finder->type == AM_FINDER_TYPE_STRING)
					ret = AM_STRING(finder->callback, am, finder->arg);
				else if (finder->type == AM_FINDER_TYPE_CALLBACK)
					ret = AM_CALLBACK(finder->callback, am);
				else if (finder->type == AM_FINDER_TYPE_AUTOMATON)
					ret = AM_AUTOMATON(finder->callback, am, finder->arg,
						finder->join);
				if (ret == 1)
					am->state_curr = finder->state_next;
			}
			item = item->next;
		}
	}
}

int		am_ok(t_am *am)
{
	return (am->state_curr == am->state_final);
}

void	am_reset(t_am *am)
{
	am->tokens = NULL;
	am->state_curr = 0;
}

t_am	*am_new(const int state_final)
{
	t_am		*am;

	am = (t_am *)malloc(sizeof(t_am));
	if (am == NULL)
		return (am);
	*(int *)&am->state_final = state_final;
	am->finders = ckl_new(t_am_finder);
	if (am->finders == NULL)
	{
		free(am);
		return (NULL);
	}
	am_reset(am);
	return (am);
}

void	am_add_token(t_am *am, t_cks orig, t_cks computed)
{
	t_am_token		token;
	t_cks			nsource;

	token.type = am->curr_finder->token_type;
	token.value_orig = orig;
	token.value_computed = (computed != NULL) ? computed : cks_dup(orig);
	ckl_append(am->tokens, &token);
	nsource = am->source;
	am->source = cks_sub(am->source, cks_len(orig));
	cks_free(nsource);
}

void	am_find_callback(t_am *am, t_am_meta meta,
			t_am_callback_finder_callback cb)
{
	t_am_finder		finder;

	finder.token_type = meta.type;
	finder.type = AM_FINDER_TYPE_CALLBACK;
	finder.join = 0;
	finder.state_prev = meta.from;
	finder.state_next = meta.to;
	finder.arg = NULL;
	finder.callback = (void *)cb;
	ckl_append(am->finders, &finder);
}

int		am_finder_string(t_am *am, t_cks str)
{
	t_cks	sub;
	size_t	len;

	len = cks_len(str);
	if (cks_len(am->source) >= len)
	{
		sub = cks_sub_len(am->source, 0, len);
		if (cks_cmp_len(sub, str, len) == 0)
		{
			am_add_token(am, sub, NULL);
			return (1);
		}
		cks_free(sub);
	}
	return (0);
}

void	am_find_string(t_am *am, t_am_meta meta, char *str)
{
	t_am_finder		finder;

	finder.token_type = meta.type;
	finder.type = AM_FINDER_TYPE_STRING;
	finder.join = 0;
	finder.state_prev = meta.from;
	finder.state_next = meta.to;
	finder.arg = cks_new(str);
	finder.callback = (void *)am_finder_string;
	ckl_append(am->finders, &finder);
}

void	am_free_token_content(void *t)
{
	t_am_token	*token;

	token = t;
	cks_free(token->value_orig);
	cks_free(token->value_computed);
}

void	am_free_finder_content(void *f)
{
	t_am_finder	*finder;

	finder = f;
	if (finder->type == AM_FINDER_TYPE_STRING)
		cks_free(finder->arg);
}

void	am_free(t_am *am)
{
	if (am != NULL)
	{
		cks_free(am->source);
		ckl_free_items(am->tokens, am_free_token_content);
		ckl_free(am->tokens);
		ckl_free_items(am->finders, am_free_finder_content);
		ckl_free(am->finders);
		free(am);
	}
}

void	am_sub_free(t_am *am)
{
	if (am != NULL)
	{
		cks_free(am->source);
		ckl_free_items(am->tokens, NULL);
		ckl_free(am->tokens);
		ckl_free_items(am->finders, am_free_finder_content);
		ckl_free(am->finders);
		free(am);
	}
}

int		am_finder_automaton(t_am *am, t_am_maker maker)
{
	t_am		*nam;
	t_ckl_item	*item;
	t_am_token	joined_token;
	t_am_token	*curr_token;

	nam = maker();
	nam->source = cks_dup(am->source);
	am_run(nam);
	if (am_ok(nam))
	{
		if (am->curr_finder->join)
		{
			joined_token.value_computed = cks_new("");
			joined_token.value_orig = cks_new("");
			joined_token.type = am->curr_finder->token_type;
			item = nam->tokens->first;
			while (item)
			{
				curr_token = &ckl_data(t_am_token, item);
				joined_token.value_computed = cks_append_len(
					joined_token.value_computed,
					curr_token->value_computed,
					cks_len(curr_token->value_computed)
				);
				joined_token.value_orig = cks_append_len(
					joined_token.value_orig,
					curr_token->value_orig,
					cks_len(curr_token->value_orig)
				);
				item = item->next;
			}
			ckl_free_items(nam->tokens, am_free_token_content);
			ckl_append(nam->tokens, &joined_token);
		}
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

void	am_find_automaton(t_am *am, t_am_meta meta, t_am_maker maker)
{
	t_am_finder		finder;

	finder.token_type = meta.type;
	finder.type = AM_FINDER_TYPE_AUTOMATON;
	finder.join = meta.join;
	finder.state_prev = meta.from;
	finder.state_next = meta.to;
	finder.arg = maker;
	finder.callback = (void *)am_finder_automaton;
	ckl_append(am->finders, &finder);
}

int		am_callback_is_not_whitespace(t_am *am)
{
	char		c;

	if (cks_len(am->source) == 0)
		return (1);
	c = am->source[0];
	return (c != ' ' && c != '\t' && c != '\n' && c != '\v' && c != '\f'
		&& c != '\r');
}

t_am	*am_make_whitespace_automaton(void)
{
	t_am		*am;

	am = am_new(2);
	am_find_string(am, am_meta(.from = 0, .to = 1), " ");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\t");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\n");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\v");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\f");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\r");
	am_find_callback(am, am_meta(.from = 1, .to = 2),
		am_callback_is_not_whitespace);
	am_find_automaton(am, am_meta(.from = 1, .to = 2, .join=0),
		am_make_whitespace_automaton);
	return (am);
}

void	am_find_whitespace(t_am *am, t_am_meta meta)
{
	meta.join = 1;
	am_find_automaton(am, meta, am_make_whitespace_automaton);
}

int		am_callback_is_end(t_am *am)
{
	return (cks_len(am->source) == 0);
}

void	am_find_end(t_am *am, t_am_meta meta)
{
	am_find_callback(am, meta, am_callback_is_end);
}

void	_am_find_strings(t_am *am, t_am_meta meta, char **strings)
{
	size_t		i;

	i = 0;
	while (strings[i] != NULL)
		am_find_string(am, meta, strings[i++]);
}

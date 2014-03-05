/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:18:35 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/04 18:55:30 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cks.h"
#include "am.h"
#include "sh.h"
#include "sh_parser.h"

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
			|| am->source[i] == '"' || am->source[i] == '`')
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

t_am	*lexer_automaton_single_quote_string(void)
{
	t_am		*am;

	am = am_new(3);
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_SINGLE_QUOTE), "'");
	am_find_callback(am, am_meta(.from=1, .to=2, .type=SH_TOKEN_TYPE_SINGLE_QUOTE_STRING), lexer_callback_single_quote_string_content);
	am_find_string(am, am_meta(.from=2, .to=3, .type=SH_TOKEN_TYPE_SINGLE_QUOTE), "'");
	return (am);
}

int		lexer_callback_double_quote_string_content(t_am *am)
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
		{
			orig = cks_append_len(orig, am->source + i, 2);
			computed = cks_append_len(computed, am->source + i + 1, 1);
			i += 2;
		}
		else if (am->source[i] != '\\')
		{
			orig = cks_append_len(orig, am->source + i, 1);
			computed = cks_append_len(computed, am->source + i, 1);
			i++;
		}
		else
		{
			cks_free(orig);
			cks_free(computed);
			return (0);
		}
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

t_am	*lexer_automaton_double_quote_string(void)
{
	t_am		*am;

	am = am_new(3);
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_DOUBLE_QUOTE), "\"");
	am_find_callback(am, am_meta(.from=1, .to=2, .type=SH_TOKEN_TYPE_DOUBLE_QUOTE_STRING), lexer_callback_double_quote_string_content);
	am_find_string(am, am_meta(.from=2, .to=3, .type=SH_TOKEN_TYPE_DOUBLE_QUOTE), "\"");
	return (am);
}

/*
** meaningful characters: ; | & > < ! " ' space
*/
int		is_not_meaningful(char c)
{
	return (c != ';' && c != '|' && c != '&' && c != '!'
		&& c != '>' && c != '<' && c != '\'' && c != '"'
		&& c != ' ' && c != '\t' && c != '\v' && c != '\f'
		&& c != '\r' && c != '\n');
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
		{
			orig = cks_append_len(orig, am->source + i, 2);
			computed = cks_append_len(computed, am->source + i + 1, 1);
			i += 2;
		}
		else if (am->source[i] != '\\')
		{
			orig = cks_append_len(orig, am->source + i, 1);
			computed = cks_append_len(computed, am->source + i, 1);
			i++;
		}
		else
		{
			cks_free(orig);
			cks_free(computed);
			return (0);
		}
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

t_am	*lexer_automaton_string(void)
{
	t_am		*am;

	am = am_new(1);
	am_find_callback(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_STRING), lexer_callback_string);
	return (am);
}

t_am	*lexer_automaton_command_line_token(void)
{
	t_am		*am;

	am = am_new(1);
	am_find_whitespace(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_WHITESPACE));
	am_find_end(am, am_meta(.from=0, .to=1));
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_SEMICOLON), ";");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_LOGICAL_OR), "||");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_PIPE), "|");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_LOGICAL_AND), "&&");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_BACKGROUND), "&");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_APPEND_REDIR_OUT), ">>");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_HERE_DOC), "<<");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_REDIR_OUT), ">");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_REDIR_IN), "<");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_EXCLAMATION_POINT), "!");
	am_find_automaton(am, am_meta(.from=0, .to=1, .join=0), lexer_automaton_string);
	am_find_automaton(am, am_meta(.from=0, .to=1, .join=0), lexer_automaton_double_quote_string);
	am_find_automaton(am, am_meta(.from=0, .to=1, .join=0), lexer_automaton_single_quote_string);
	return (am);
}

int		am_lex(t_am_maker maker, const char *source, t_ckl *tokens)
{
	t_am		*am;
	t_ckl_item	*item;
	int			error;

	am = maker();
	am->source = cks_new(source);
	am_run(am);
	item = am->tokens->first;
	while (item)
	{
		ckl_append(tokens, &ckl_data(t_am_token, item));
		item = item->next;
	}
	while (am_ok(am) == 1 && cks_len(am->source) > 0)
	{
		ckl_free_items(am->tokens, NULL);
		ckl_free(am->tokens);
		am_run(am);
		item = am->tokens->first;
		while (item)
		{
			ckl_append(tokens, &ckl_data(t_am_token, item));
			item = item->next;
		}
	}
	error = !am_ok(am);
	am_sub_free(am);
	return (error);
}

void	sh_remove_useless_tokens(t_ckl *tokens)
{
	t_ckl_item	*item;
	t_ckl_item	*next;

	item = tokens->first;
	while (item)
	{
		next = item->next;
		t_am_token	*token = &ckl_data(t_am_token, item);
		if (token->type == SH_TOKEN_TYPE_DOUBLE_QUOTE
			|| token->type == SH_TOKEN_TYPE_SINGLE_QUOTE)
		{
			cks_free(token->value_orig);
			cks_free(token->value_computed);
			ckl_withdraw(tokens, item);
			ckl_free_item(item);
		}
		item = next;
	}
}

int		sh_type_is_op(int type)
{
	return (type == SH_TOKEN_TYPE_SEMICOLON
			|| type == SH_TOKEN_TYPE_LOGICAL_AND
			|| type == SH_TOKEN_TYPE_LOGICAL_OR
			|| type == SH_TOKEN_TYPE_PIPE);
}

int		sh_token_is_quoted_string(t_am_token *t)
{
	return (t->type == SH_TOKEN_TYPE_DOUBLE_QUOTE_STRING
		|| t->type == SH_TOKEN_TYPE_SINGLE_QUOTE_STRING);
}

int		sh_token_is_string(t_am_token *t)
{
	return (t->type == SH_TOKEN_TYPE_STRING || sh_token_is_quoted_string(t)
			|| t->type == SH_TOKEN_TYPE_QUOTE_STRING);
}

void	sh_concat_strings(t_ckl *t)
{
	t_ckl_item	*i;
	t_ckl_item	*prev;
	t_am_token	*tok;
	t_am_token	*next;

	i = t->first;
	while (i != NULL)
	{
		tok = &ckl_data(t_am_token, i);
		if (sh_token_is_string(tok))
		{
			if (sh_token_is_quoted_string(tok))
				tok->type = SH_TOKEN_TYPE_QUOTE_STRING;
			i = i->next;
			while (i != NULL && (next = &ckl_data(t_am_token, i)) != NULL)
			{
				if (sh_token_is_string(next))
				{
					if (sh_token_is_quoted_string(next))
						tok->type = SH_TOKEN_TYPE_QUOTE_STRING;
					tok->value_orig = cks_append(tok->value_orig, next->value_orig);
					tok->value_computed = cks_append(tok->value_computed, next->value_computed);
					prev = i;
					i = i->next;
					ckl_withdraw(t, prev);
				}
				else
				{
					break ;
				}
			}
		}
		if (i != NULL)
			i = i->next;
	}
}

void	sh_remove_whitespace(t_ckl *tokens)
{
	t_ckl_item	*item;

	item = tokens->first;
	while (item)
	{
		t_am_token	*token = &ckl_data(t_am_token, item);
		if (token->type == SH_TOKEN_TYPE_WHITESPACE)
		{
			cks_free(token->value_orig);
			cks_free(token->value_computed);
			ckl_withdraw(tokens, item);
			ckl_free_item(item);
		}
		item = item->next;
	}
}

/*
** Lex and remove quotes since they are useless.
*/
int		sh_lex(const char *src, t_ckl *tokens)
{
	if (am_lex(lexer_automaton_command_line_token, src, tokens) != 0)
		return (-1);
	sh_remove_useless_tokens(tokens);
	sh_concat_strings(tokens);
	sh_remove_whitespace(tokens);
	return (0);
}

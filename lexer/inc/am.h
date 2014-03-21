/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:19:03 by ckleines          #+#    #+#             */
/*   Updated: 2014/02/28 03:50:38 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AM_H

# define AM_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "cks.h"
# include "ckl.h"

# define AM_FINDER_TYPE_AUTOMATON (1)
# define AM_FINDER_TYPE_STRING (2)
# define AM_FINDER_TYPE_CALLBACK (3)

# define AM_JOIN_TOKENS (1)

typedef struct						s_am_meta
{
	int								from;
	int								to;
	int								type;
	int								join;
}									t_am_meta;

typedef struct						s_am_finder
{
	int								join;
	int								state_prev;
	int								state_next;
	void							*callback;
	int								type;
	void							*arg;
	int								token_type;
}									t_am_finder;

typedef struct						s_am
{
	t_ckl							*finders;
	t_ckl							*tokens;
	int								state_curr;
	int								state_final;
	t_cks							source;
	t_am_finder						*curr_finder;
}									t_am;

typedef t_am	*(*t_am_maker)(void);

typedef int		(*t_am_string_finder_callback)(t_am *am, char *str);
typedef int		(*t_am_automaton_finder_callback)(t_am *am, t_am_maker maker, int join);
typedef int		(*t_am_callback_finder_callback)(t_am *am);

# define AM_STRING(cb, am, str) ((t_am_string_finder_callback)(cb))((am), (char *)(str))
# define AM_CALLBACK(cb, am) ((t_am_callback_finder_callback)(cb))((am))
# define AM_AUTOMATON(cb, am, maker, join) ((t_am_automaton_finder_callback)(cb))((am), (t_am_maker)maker, join)

typedef struct						s_am_token
{
	char							*value_computed;
	char							*value_orig;
	int								type;
}									t_am_token;

void				am_add_token(t_am *am, t_cks orig, t_cks computed);
t_am				*am_new(const int state_final);
void				am_run(t_am *am);
void				am_find_string(t_am *am, t_am_meta meta, char *str);
void				am_find_automaton(t_am *am, t_am_meta meta, t_am_maker maker);
void				am_find_callback(t_am *am, t_am_meta meta, t_am_callback_finder_callback cb);
void				am_find_whitespace(t_am *am, t_am_meta meta);
void				am_find_end(t_am *am, t_am_meta meta);
void				am_free(t_am *am);
int					am_ok(t_am *am);
void				am_reset(t_am *am);
# define am_meta(...) ((t_am_meta){__VA_ARGS__})
int					am_lex(t_am_maker maker, const char *source, t_ckl *tokens);
void				am_free_token_content(void *t);
void				am_sub_free(t_am *am);
int					am_finder_automaton(t_am *am, t_am_maker maker);
int					am_callback_is_end(t_am *am);
int					am_finder_string(t_am *am, t_cks str);
t_am				*am_make_whitespace_automaton(void);
void				am_free_finder_content(void *f);
int					am_callback_is_not_whitespace(t_am *am);

#endif

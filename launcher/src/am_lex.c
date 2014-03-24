/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:50:53 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 17:59:57 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

void	st_add_tokens(t_ckl *from, t_ckl *to)
{
	t_ckl_item	*item;

	item = from->first;
	while (item)
	{
		ckl_append(to, &ckl_data(t_am_token, item));
		item = item->next;
	}
}

int		am_lex(t_am_maker maker, const char *source, t_ckl *tokens)
{
	t_am		*am;
	int			error;

	am = maker();
	am->source = cks_new(source);
	am_run(am);
	st_add_tokens(am->tokens, tokens);
	while (am_ok(am) == 1 && cks_len(am->source) > 0)
	{
		ckl_free_items(am->tokens, NULL);
		ckl_free(am->tokens);
		am_run(am);
		st_add_tokens(am->tokens, tokens);
	}
	error = !am_ok(am);
	am_sub_free(am);
	return (error);
}

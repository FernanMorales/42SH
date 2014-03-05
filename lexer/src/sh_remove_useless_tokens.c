/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_useless_tokens.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:50:38 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:10:22 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "am.h"

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

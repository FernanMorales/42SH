/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_whitespace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:49:18 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:10:32 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "am.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:29:34 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:48:40 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

void		sh_print_tokens(t_ckl *tokens)
{
	t_ckl_item	*item;
	t_am_token	*token;

	item = tokens->first;
	while (item)
	{
		token = &ckl_data(t_am_token, item);
		printf("%s => `%s`\n", sh_types[token->type], token->value_computed);
		item = item->next;
	}
}

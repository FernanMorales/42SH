/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parse_num_log_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:16:16 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:16:17 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

unsigned	sh_parse_num_log_ops(t_ckl *tokens)
{
	t_ckl_item		*item;
	t_am_token		*tok;
	unsigned		num;

	num = 0;
	item = tokens->first;
	while (item)
	{
		tok = &ckl_data(t_am_token, item);
		if (tok->type == SH_TOKEN_TYPE_SEMICOLON)
			return (num);
		if (tok->type == SH_TOKEN_TYPE_LOGICAL_AND
			|| tok->type == SH_TOKEN_TYPE_LOGICAL_OR)
			num++;
		item = item->next;
	}
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_replace_redirections_out.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:25:54 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/06 17:26:09 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

void	sh_replace_redirections_out(t_ckl *t, t_ckl_item *start,
			t_ckl_item *end, const char *base)
{
	t_ckl_item		*i;
	t_am_token		*curr;
	t_am_token		*next;

	i = start;
	while (i && i->next)
	{
		next = &ckl_data(t_am_token, i->next);
		curr = &ckl_data(t_am_token, i);
		if (curr->type == SH_TOKEN_TYPE_REDIR_OUT
			&& sh_token_is_string(next))
		{
			sh_outfile(t, end, next->value_computed, base);
			ckl_withdraw(t, i);
			ckl_withdraw(t, i->next);
			i = i->next->next;
			continue ;
		}
		else if (curr->type == SH_TOKEN_TYPE_APPEND_REDIR_OUT
			&& sh_token_is_string(next))
		{
			sh_outfile_append(t, end, next->value_computed, base);
			ckl_withdraw(t, i);
			ckl_withdraw(t, i->next);
			i = i->next->next;
			continue ;
		}
		i = i->next;
	}
}

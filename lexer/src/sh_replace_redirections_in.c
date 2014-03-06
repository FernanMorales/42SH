/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_replace_redirections_in.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:27:22 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/06 17:27:35 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

void	sh_replace_redirections_in(t_ckl *t, t_ckl_item *start,
			const char *base)
{
	t_ckl_item		*i;
	t_am_token		*curr;
	t_am_token		*next;

	i = start;
	while (i && i->next)
	{
		next = &ckl_data(t_am_token, i->next);
		curr = &ckl_data(t_am_token, i);
		if (curr->type == SH_TOKEN_TYPE_REDIR_IN
			&& sh_token_is_string(next))
		{
			sh_infile(t, start, next->value_computed, base);
			ckl_withdraw(t, i);
			ckl_withdraw(t, i->next);
			i = i->next->next;
			continue ;
		}
		else if (curr->type == SH_TOKEN_TYPE_HERE_DOC
			&& sh_token_is_string(next))
		{
			sh_heredoc(t, start, next->value_computed, base);
			ckl_withdraw(t, i);
			ckl_withdraw(t, i->next);
			i = i->next->next;
			continue ;
		}
		i = i->next;
	}
}

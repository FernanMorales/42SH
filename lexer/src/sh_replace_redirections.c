/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_replace_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:22:44 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/06 17:23:12 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "am.h"

void	sh_replace_redirections(t_ckl *t, const char *base)
{
	t_ckl_item		*i;
	t_ckl_item		*start;

	i = t->first;
	while (i != NULL)
	{
		while (i && sh_type_is_op(ckl_data(t_am_token, i).type))
			i = i->next;
		if ((start = i))
			sh_replace_redirections_in(t, start, base);
		while (i && i->next && !sh_type_is_op(ckl_data(t_am_token, i->next).type))
			i = i->next;
		if (i)
			sh_replace_redirections_out(t, start, i, base);
		if (i)
			i = i->next;
	}
}

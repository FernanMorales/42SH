/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_has_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:20:59 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:52:59 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			sh_has_redirection(t_ckl *tokens)
{
	t_am_token	*tok1;
	t_am_token	*tok2;

	if (tokens->first == NULL || tokens->first->next == NULL)
		return (0);
	tok1 = &ckl_data(t_am_token, tokens->first);
	tok2 = &ckl_data(t_am_token, tokens->first->next);
	return ((tok1->type == SH_TOKEN_TYPE_REDIR_IN
	|| tok1->type == SH_TOKEN_TYPE_HERE_DOC
	|| tok1->type == SH_TOKEN_TYPE_REDIR_OUT
	|| tok1->type == SH_TOKEN_TYPE_APPEND_REDIR_OUT)
	&& (tok2->type == SH_TOKEN_TYPE_STRING
	|| tok2->type == SH_TOKEN_TYPE_QUOTE_STRING));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_has_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:15:19 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:15:20 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			sh_has_arg(t_ckl *tokens)
{
	t_am_token	*tok;

	if (tokens->first == NULL)
		return (0);
	tok = &ckl_data(t_am_token, tokens->first);
	return (tok->type == SH_TOKEN_TYPE_STRING
		|| tok->type == SH_TOKEN_TYPE_QUOTE_STRING);
}

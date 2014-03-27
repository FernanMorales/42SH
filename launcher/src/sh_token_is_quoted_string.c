/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_token_is_quoted_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:50:07 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:48:55 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "am.h"

int		sh_token_is_quoted_string(t_am_token *t)
{
	return (t->type == SH_TOKEN_TYPE_DOUBLE_QUOTE_STRING
	|| t->type == SH_TOKEN_TYPE_SINGLE_QUOTE_STRING
	|| t->type == SH_TOKEN_TYPE_QUOTE_STRING);
}

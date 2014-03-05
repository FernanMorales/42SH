/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_token_is_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:49:51 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:10:41 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "am.h"

int		sh_token_is_string(t_am_token *t)
{
	return (t->type == SH_TOKEN_TYPE_STRING || sh_token_is_quoted_string(t));
}

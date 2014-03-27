/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_type_is_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:50:20 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:50:12 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "am.h"

int		sh_type_is_op(int type)
{
	return (type == SH_TOKEN_TYPE_SEMICOLON
	|| type == SH_TOKEN_TYPE_LOGICAL_AND
	|| type == SH_TOKEN_TYPE_LOGICAL_OR
	|| type == SH_TOKEN_TYPE_PIPE);
}

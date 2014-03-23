/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_free_token_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:24:46 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:24:47 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_free_token_content(void *t)
{
	t_am_token	*token;

	token = t;
	cks_free(token->value_orig);
	cks_free(token->value_computed);
}

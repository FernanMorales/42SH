/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_outfile_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:26:26 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/06 17:26:42 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

void	sh_outfile_append(t_ckl *tokens, t_ckl_item *end,
			const t_cks boundary, const char *base)
{
	t_am_token		one;
	t_am_token		two;
	t_am_token		three;

	one.type = SH_TOKEN_TYPE_STRING;
	one.value_orig = cks_append(cks_new(base), "42sh-outfile-append");
	one.value_computed = cks_append(cks_new(base), "42sh-outfile-append");
	two.type = SH_TOKEN_TYPE_STRING;
	two.value_orig = cks_dup(boundary);
	two.value_computed = cks_dup(boundary);
	three.type = SH_TOKEN_TYPE_PIPE;
	three.value_orig = cks_new("|");
	three.value_computed = cks_new("|");
	ckl_append_item(tokens, end, &three);
	ckl_append_item(tokens, end->next, &one);
	ckl_append_item(tokens, end->next->next, &two);
}

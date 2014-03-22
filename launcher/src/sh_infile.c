/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_infile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:28:25 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/06 17:28:38 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

void	sh_infile(t_ckl *tokens, t_ckl_item *start, const t_cks file,
			const char *base)
{
	t_am_token		one;
	t_am_token		two;
	t_am_token		three;

	one.type = SH_TOKEN_TYPE_STRING;
	one.value_orig = cks_append(cks_new(base), "42sh-infile");
	one.value_computed = cks_append(cks_new(base), "42sh-infile");
	two.type = SH_TOKEN_TYPE_STRING;
	two.value_orig = cks_dup(file);
	two.value_computed = cks_dup(file);
	three.type = SH_TOKEN_TYPE_PIPE;
	three.value_orig = cks_new("|");
	three.value_computed = cks_new("|");
	ckl_prepend_item(tokens, start, &one);
	ckl_prepend_item(tokens, start, &two);
	ckl_prepend_item(tokens, start, &three);
}

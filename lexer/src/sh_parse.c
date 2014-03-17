/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:31:03 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/06 18:41:36 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

/*
** use sh_print_tokens(tokens); to print
*/
int			sh_parse(const char *src, t_ckbt *tree, const char *basepath)
{
	t_ckl	*tokens;
	int		brackets;

	if ((brackets = sh_check_bracketing(src)) != 0)
		return (brackets);
	if ((tokens = ckl_new(t_am_token)) == NULL)
		return (-2);
	if (sh_lex(src, tokens) != 0)
		return (-1);
	sh_replace_redirections(tokens, basepath);
	return (sh_build_tree(tokens, tree) ? -1 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:48:55 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:10:10 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "am.h"

/*
** Lex and remove quotes since they are useless.
*/
int		sh_lex(const char *src, t_ckl *tokens)
{
	if (am_lex(lexer_automaton_command_line_token, src, tokens) != 0)
		return (-1);
	sh_remove_useless_tokens(tokens);
	sh_concat_strings(tokens);
	sh_remove_whitespace(tokens);
	return (0);
}

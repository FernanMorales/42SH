/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton_single_quote_string.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:53:25 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 15:17:38 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

t_am	*lexer_automaton_single_quote_string(void)
{
	t_am		*am;

	am = am_new(3);
	am_find_string(am,
		AM_META(.from = 0, .to = 1, .type = SH_TOKEN_TYPE_SINGLE_QUOTE), "'");
	am_find_callback(am,
		AM_META(.from = 1, .to = 2, .type = SH_TOKEN_TYPE_SINGLE_QUOTE_STRING),
		lexer_callback_single_quote_string_content);
	am_find_string(am,
		AM_META(.from = 2, .to = 3, .type = SH_TOKEN_TYPE_SINGLE_QUOTE), "'");
	return (am);
}

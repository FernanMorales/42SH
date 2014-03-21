/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton_double_quote_string.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:52:26 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:00:56 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

t_am	*lexer_automaton_double_quote_string(void)
{
	t_am		*am;

	am = am_new(3);
	am_find_string(am, am_meta(.from = 0, .to = 1,
		.type = SH_TOKEN_TYPE_DOUBLE_QUOTE), "\"");
	am_find_callback(am,
		am_meta(.from = 1, .to = 2, .type = SH_TOKEN_TYPE_DOUBLE_QUOTE_STRING),
		lexer_callback_double_quote_string_content);
	am_find_string(am,
		am_meta(.from = 2, .to = 3, .type = SH_TOKEN_TYPE_DOUBLE_QUOTE), "\"");
	return (am);
}

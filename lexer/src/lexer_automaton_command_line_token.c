/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton_command_line_token.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:51:19 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:00:21 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

t_am	*lexer_automaton_command_line_token(void)
{
	t_am		*am;

	am = am_new(1);
	am_find_whitespace(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_WHITESPACE));
	am_find_end(am, am_meta(.from=0, .to=1));
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_SEMICOLON), ";");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_LOGICAL_OR), "||");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_PIPE), "|");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_LOGICAL_AND), "&&");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_BACKGROUND), "&");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_APPEND_REDIR_OUT), ">>");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_HERE_DOC), "<<");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_REDIR_OUT), ">");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_REDIR_IN), "<");
	am_find_string(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_EXCLAMATION_POINT), "!");
	am_find_automaton(am, am_meta(.from=0, .to=1, .join=0), lexer_automaton_string);
	am_find_automaton(am, am_meta(.from=0, .to=1, .join=0), lexer_automaton_double_quote_string);
	am_find_automaton(am, am_meta(.from=0, .to=1, .join=0), lexer_automaton_single_quote_string);
	return (am);
}

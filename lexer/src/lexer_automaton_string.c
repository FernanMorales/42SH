/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:51:35 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/05 18:01:17 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "am.h"
#include "sh.h"

t_am	*lexer_automaton_string(void)
{
	t_am		*am;

	am = am_new(1);
	am_find_callback(am, am_meta(.from=0, .to=1, .type=SH_TOKEN_TYPE_STRING), lexer_callback_string);
	return (am);
}

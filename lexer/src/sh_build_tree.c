/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_build_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:31:27 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/06 19:14:04 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Grammar:
**
** cmd_line := [ seq_cmd ]*
**
** seq_cmd := log_cmd [ ; cmd_line ]*
**
** log_op := '||' | '&&'
**
** log_cmd := pipe_cmd [ log_op log_cmd ]*
**
** pipe_cmd := cmd [ | pipe_cmd ]*
**
** cmd := string [ string ]*
*/

int			sh_parse_seq_cmd(t_ckl *tokens, t_ckbt *tree)
{
	t_am_token		*tok;

	if (tokens->first == NULL)
		return (1);
	// ...
}

int			sh_parse_seq_cmd(t_ckl *tokens, t_ckbt *tree)
{
	t_am_token		*tok;

	if (tokens->first == NULL)
		return (1);
	if (sh_parse_log_cmd(tokens, tree) == 1)
	{
		tok = &ckl_data(t_am_token, tokens->first);
		if (tok->type != SH_TOKEN_TYPE_SEMICOLON)
		{
			return (1);
		}
		else
		{
			ckl_withdraw(tokens->first);
			ckl_free_item(tokens->first);
			return (sh_parse_cmd_line(tokens, tree));
		}
	}
	return (0);
}

int			sh_parse_cmd_line(t_ckl *tokens, t_ckbt *tree)
{
	if (tokens->first == NULL)
		return (0);
	return (sh_parse_non_empty_cmd_line(tokens, tree));
}

int			sh_build_tree(t_ckl *tokens, t_ckbt *tree)
{
	return (sh_parse_cmd_line(tokens, tree));
}

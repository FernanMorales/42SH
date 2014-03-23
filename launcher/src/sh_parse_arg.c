/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:19:35 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:19:35 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			sh_parse_arg(t_ckl *tokens, t_sh_command *cmd)
{
	t_am_token	*tok;

	tok = &ckl_data(t_am_token, tokens->first);
	ckl_append(cmd->argv, &tok->value_computed);
	ckl_withdraw(tokens, tokens->first);
	return (0);
}

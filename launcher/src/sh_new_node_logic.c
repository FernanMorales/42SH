/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_new_node_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:20:49 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:20:50 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_ckbt_node	*sh_new_node_logic(t_ckbt *tree, t_sh_token_type type)
{
	t_sh_command	cmd;

	if (type == SH_TOKEN_TYPE_LOGICAL_AND)
		cmd.type = SH_COMMAND_TYPE_AND;
	else
		cmd.type = SH_COMMAND_TYPE_OR;
	cmd.commands = NULL;
	cmd.argv = NULL;
	cmd.in = NULL;
	cmd.in_is_heredoc = 0;
	cmd.out = NULL;
	cmd.out_append = 0;
	return (ckbt_new_node(tree, &cmd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_new_node_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:17:06 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:17:07 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_ckbt_node	*sh_new_node_pipe(t_ckbt *tree)
{
	t_sh_command	cmd;

	cmd.type = SH_COMMAND_TYPE_PIPE;
	cmd.commands = NULL;
	cmd.argv = NULL;
	cmd.in = NULL;
	cmd.in_is_heredoc = 0;
	cmd.out = NULL;
	cmd.out_append = 0;
	return (ckbt_new_node(tree, &cmd));
}

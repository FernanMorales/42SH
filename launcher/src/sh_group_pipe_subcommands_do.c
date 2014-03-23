/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_group_pipe_subcommands_do.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:15:59 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:16:00 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		sh_group_pipe_subcommands_do(t_ckbt_node *root, t_ckl *cmds)
{
	t_sh_command		*cmd;

	if (root)
	{
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_EXEC)
			ckl_append(cmds, cmd);
		else if (cmd->type == SH_COMMAND_TYPE_PIPE)
		{
			sh_group_pipe_subcommands_do(root->left, cmds);
			sh_group_pipe_subcommands_do(root->right, cmds);
		}
	}
}

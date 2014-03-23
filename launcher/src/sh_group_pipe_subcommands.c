/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_group_pipe_subcommands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:15:54 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:15:55 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		sh_group_pipe_subcommands(t_ckbt_node *root)
{
	t_sh_command		*cmd;

	if (root)
	{
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_PIPE)
		{
			cmd->commands = ckl_new(t_sh_command);
			sh_group_pipe_subcommands_do(root->left, cmd->commands);
			sh_group_pipe_subcommands_do(root->right, cmd->commands);
			root->left = NULL;
			root->right = NULL;
		}
		else
		{
			sh_group_pipe_subcommands(root->left);
			sh_group_pipe_subcommands(root->right);
		}
	}
}

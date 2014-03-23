/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:22:40 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:22:41 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static char	*st_types[5] = {
	"pipe",
	"and",
	"or",
	"semicolon",
	"command"
};

void		debug_tree(t_ckbt *tree, t_ckbt_node *node)
{
	t_sh_command		*command;
	t_sh_command		*cmd;
	t_ckl_item			*cmd_item;
	t_ckl_item			*item;

	command = &ckbt_data(t_sh_command, node);
	dprintf(2, "%s : ", st_types[command->type]);
	if (command->argv)
	{
		dprintf(2, " in =>  %s ", command->in);
		dprintf(2, " out =>  %s ", command->out);
		item = command->argv->first;
		while (item)
		{
			dprintf(2, " [ %s ] ", ckl_data(t_cks, item));
			item = item->next;
		}
	}
	if (command->commands)
	{
		cmd_item = command->commands->first;
		while (cmd_item)
		{
			dprintf(2, "COMMAND => ");
			cmd = &ckl_data(t_sh_command, cmd_item);
			dprintf(2, " in =>  %s ", cmd->in);
			dprintf(2, " out =>  %s ", cmd->out);
			if (cmd->argv)
			{
				item = cmd->argv->first;
				while (item)
				{
					dprintf(2, " [ %s ] ", ckl_data(t_cks, item));
					item = item->next;
				}
			}
			dprintf(2, " / ");
			cmd_item = cmd_item->next;
		}
	}
	dprintf(2, "\n");
	(void)tree;
}

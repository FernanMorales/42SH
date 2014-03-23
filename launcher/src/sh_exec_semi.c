/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_semi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:20:04 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:20:05 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		sh_exec_semi(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root)
{
	t_sh_command		*cmd;
	int					error;

	error = 1;
	if (root)
	{
		error = 0;
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_SEMICOLON)
		{
			if ((error = sh_exec_log(env, tree, root->left)))
				return (error);
			if ((error = sh_exec_semi(env, tree, root->right)))
				return (error);
		}
		else
		{
			return (sh_exec_log(env, tree, root));
		}
	}
	return (error);
}

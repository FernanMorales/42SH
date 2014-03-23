/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_log.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:12:11 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:12:12 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		sh_exec_log(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root)
{
	t_sh_command		*cmd;
	int					error;

	if (root)
	{
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_AND)
		{
			if ((error = sh_exec_log(env, tree, root->left)))
				return (error);
			if (env->last_ret == 0)
				return (sh_exec_pipe(env, tree, root->right));
		}
		else if (cmd->type == SH_COMMAND_TYPE_OR)
		{
			if ((error = sh_exec_log(env, tree, root->left)))
				return (error);
			if (env->last_ret != 0)
				return (sh_exec_pipe(env, tree, root->right));
		}
		else
			return (sh_exec_pipe(env, tree, root));
	}
	return (1);
}

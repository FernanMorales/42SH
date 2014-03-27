/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_to_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <ckleines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:39:26 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 14:39:27 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

t_sh_builtin	*sh_cmd_to_builtin(t_sh_command *cmd)
{
	t_cks		prog;
	size_t		i;

	prog = ckl_data(t_cks, cmd->argv->first);
	i = 0;
	while (sh_builtin[i].name != NULL)
	{
		if (cks_cmp(prog, sh_builtin[i].name) == 0)
			return (&sh_builtin[i]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_build_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:31:27 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 15:00:46 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			sh_build_tree(t_ckl *tokens, t_ckbt *tree)
{
	int		error;

	if ((error = sh_parse_cmd_line(tokens, tree, &tree->root)))
		return (error);
	sh_group_pipe_subcommands(tree->root);
	return (0);
}

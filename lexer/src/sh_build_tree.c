/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_build_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:31:27 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/19 17:06:57 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Grammar:
**
** cmd_line := [ seq_cmd ]*
**
** seq_cmd := log_cmd [ ; cmd_line ]*
**
** log_op := '||' | '&&'
**
** log_cmd := pipe_cmd [ log_op log_cmd ]*
**
** pipe_cmd := cmd [ | pipe_cmd ]*
**
** redir_op := << | < | > | >>
**
** redir := redir_op string
**
** cmd := [ redir ]* string [ string | redir ]*
*/
int			sh_build_tree(t_ckl *tokens, t_ckbt *tree)
{
	int		error;

	if ((error = sh_parse_cmd_line(tokens, tree, &tree->root)))
		return (error);
	sh_group_pipe_subcommands(tree->root);
	return (0);
}

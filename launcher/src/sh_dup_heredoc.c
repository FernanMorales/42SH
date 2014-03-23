/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_dup_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:20:24 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:20:25 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		sh_dup_heredoc(t_sh_command *cmd)
{
	int		fd;

	if (!cmd->in || !cmd->in_is_heredoc || !cmd->heredoc_success)
		return (0);
	fd = open("/tmp/42sh-heredoc", O_RDONLY);
	if (fd != -1)
	{
		dup2(fd, 0);
		return (0);
	}
	return (1);
}

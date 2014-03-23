/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_dup_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:20:11 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:20:12 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		sh_dup_outfile(t_sh_command *cmd)
{
	int		fd;

	if (!cmd->out)
		return (0);
	if ((fd = open(cmd->out, O_WRONLY | O_CREAT
		| ((cmd->out_append) ? O_APPEND : O_TRUNC), 0777)) != -1)
	{
		close(1);
		dup2(fd, 1);
	}
	return (1);
}

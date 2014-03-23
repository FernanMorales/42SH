/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:20:20 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/23 15:20:21 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		sh_dup(t_sh_command *cmd)
{
	sh_dup_heredoc(cmd);
	sh_dup_infile(cmd);
	sh_dup_outfile(cmd);
	return (0);
}

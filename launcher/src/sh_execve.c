/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:19:57 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/27 15:01:15 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

/*
** This MUST run in a fork, or else it will
** take over the current process.
*/
int		sh_execve(t_sh_command *cmd)
{
	t_cks		*argv;
	t_cks		full_prog;

	argv = sh_get_argv(cmd);
	if (argv == NULL || argv[0] == NULL
	|| (full_prog = sh_full_prog(argv[0])) == NULL)
	{
		write(2, "42sh: command not found\n", 24);
		exit(1);
	}
	execve(full_prog, argv, environ);
	write(2, "42sh: command not found\n", 24);
	exit(1);
}

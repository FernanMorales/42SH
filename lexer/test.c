/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 02:19:46 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/07 02:34:45 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sh_parser.h"
#include "ckl.h"
#include "cks.h"
#include "ckbt.h"
#include "ckstd.h"
#include "am.h"

char		*types[5] = {
	"pipe",
	"and",
	"or",
	"semicolon",
	"command"
};

void	debug_tree(t_ckbt *tree, t_ckbt_node *node)
{
	t_sh_command		*command;

	(void)tree;
	command = &ckbt_data(t_sh_command, node);
	write(2, types[command->type], ckstd_strlen(types[command->type]));
}

int		main(void)
{
	int		error;
	t_ckbt	*tree;

	tree = ckbt_new(t_sh_command);
	error = sh_parse(cks_get_line(0), tree, "/root/dir/");
	ckbt_debug(tree, debug_tree);
	printf("%d\n", error);
	(void)tree;
	return (error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:11:02 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/08 11:10:24 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		ftsh_init_env(t_ftsh_env *env, int argc, const char **argv)
{
	char		*path;
	char		*dir;

	path = getcwd(NULL, 0);
	if (path == NULL || argc < 1 || argv[0] == NULL)
		return (1);
	dir = ckf_dirname(argv[0]);
	if (dir == NULL || (env->base = cks_new(path)) == NULL
		|| (env->base = cks_append(env->base, "/")) == NULL
		|| (env->base = cks_append(env->base, dir)) == NULL)
		return (1);
	cks_free(dir);
	return (0);
}

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

int		main(int argc, const char **argv)
{
	t_ftsh_env		env;
	int				error;
	t_ckbt			*tree;

	if (ftsh_init_env(&env, argc, argv) == 0)
	{
		tree = ckbt_new(t_sh_command);
		error = sh_parse(cks_get_line(0), tree, env.base);
		ckbt_debug(tree, debug_tree);
		printf("%d\n", error);
	}
	return (0);
}

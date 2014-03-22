/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:11:02 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/19 19:06:38 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		main(int argc, const char **argv)
{
	t_sh_env		env;
	int				error;
	t_ckbt			*tree;
	t_cks			line;

	if (sh_init_env(&env, argc, argv) == 0)
	{
		write(1, "$> ", 3);
		while ((line = cks_get_line(0)) != NULL)
		{
			tree = ckbt_new(t_sh_command);
			error = sh_parse(line, tree, env.base);
			//ckbt_debug(tree, debug_tree);
			if (!error)
				sh_exec(&env, tree);
			else
				printf("42sh: syntax error\n");
			cks_free(line);
			write(1, "$> ", 3);
		}
		/*
		tree = ckbt_new(t_sh_command);
		// pour les termcaps, quelque chose du genre ceci,
		// qui boucle sur sh_parse tant que le retour != 0
		// sh_parse((const char *)chaine, tree, (const char *)env->base);
		char *cmd = termcap(&env, tree);
		*/
	}
	return (0);
}

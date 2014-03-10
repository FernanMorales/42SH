/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:11:02 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/08 11:30:19 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		ftsh_init_env(t_ftsh_env *env, int argc, const char **argv)
{
	char		*path;
	char		*dir;
	const char	*tty;

	path = getcwd(NULL, 0);
	if (path == NULL || argc < 1 || argv == NULL || argv[0] == NULL)
		return (1);
	dir = ckf_dirname(argv[0]);
	if ((tty = ttyname(0)) == NULL
		|| (env->tty_fd = open(tty, O_WRONLY) == -1))
		return (1);
	if (dir == NULL || (env->base = cks_new(path)) == NULL
		|| (env->base = cks_append(env->base, "/")) == NULL
		|| (env->base = cks_append(env->base, dir)) == NULL)
		return (1);
	cks_free(dir);
	return (0);
}

int		main(int argc, const char **argv)
{
	t_ftsh_env		env;
	int				error;
	t_ckbt			*tree;

	if (ftsh_init_env(&env, argc, argv) == 0)
	{
		tree = ckbt_new(t_sh_command);
		// pour les termcaps, quelque chose du genre ceci,
		// qui boucle sur sh_parse tant que le retour != 0
		// sh_parse((const char *)chaine, tree, (const char *)env->base);
		char *cmd = termcap(&env, tree);
	}
	return (0);
}

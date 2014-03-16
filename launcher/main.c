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

int		sh_init_env(t_sh_env *env, int argc, const char **argv)
{
	char		*path;
	char		*dir;
	const char	*tty;

	path = getcwd(NULL, 0);
	if (path == NULL || argc < 1 || argv == NULL || argv[0] == NULL)
		return (1);
	if ((tty = ttyname(0)) == NULL
		|| (env->tty_fd = open(tty, O_WRONLY) == -1))
		return (1);
	//dir = ckf_dirname(argv[0]);
	dir = cks_new("./");
	if (dir == NULL || (env->base = cks_new(path)) == NULL
		|| (env->base = cks_append(env->base, "/")) == NULL
		|| (env->base = cks_append(env->base, dir)) == NULL)
		return (1);
	cks_free(dir);
	env->last_ret = 0;
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

	command = &ckbt_data(t_sh_command, node);
	write(2, types[command->type], ckstd_strlen(types[command->type]));
	(void)tree;
}

t_cks	*sh_get_argv(t_sh_command *cmd)
{
	t_cks		*argv;
	t_ckl_item	*item;
	size_t		i;

	if (cmd == NULL || cmd->argv == NULL)
		return (NULL);
	argv = (t_cks *)malloc(sizeof(t_cks) * (cmd->argv->length + 1));
	if (argv == NULL)
		return (NULL);
	i = 0;
	item = cmd->argv->first;
	while (item)
	{
		argv[i] = ckl_data(t_cks, item);
		item = item->next;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

/*
** format: arg [arg]*
** where arg is a string
*/
int		sh_execve(t_sh_env *env, t_sh_command *cmd)
{
	t_cks		*argv;
	pid_t		pid;

	argv = sh_get_argv(cmd);
	if (argv == NULL || argv[0] == NULL)
		return (1);
	pid = fork();
	if (pid == -1)
	{
		// error
	}
	else if (pid == 0)
	{
		// son
		execve(argv[0], argv, environ);
		printf("execve failed with %s\n", argv[0]);
		exit(1);
	}
	else
	{
		// father with son PID
		wait(NULL);
	}
	return (1);
	(void)env;
}

int		sh_exec_pipe(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root)
{
	t_sh_command		*cmd;
	int					error;

	error = 1;
	if (root)
	{
		error = 0;
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_EXEC)
		{
			return (sh_execve(env, cmd));
		}
		else if (cmd->type == SH_COMMAND_TYPE_PIPE)
		{
			sh_exec_pipe(env, tree, root->left);
			sh_exec_pipe(env, tree, root->right);
			return (0);
		}
		else
		{
			return (1);
		}
	}
	return (error);
}

int		sh_exec_log(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root)
{
	t_sh_command		*cmd;
	int					error;

	error = 1;
	if (root)
	{
		error = 0;
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_AND)
		{
			if ((error = sh_exec_log(env, tree, root->left)))
				return (error);
			if (env->last_ret == 0)
				return (sh_exec_pipe(env, tree, root->right));
		}
		else if (cmd->type == SH_COMMAND_TYPE_OR)
		{
			if ((error = sh_exec_log(env, tree, root->left)))
				return (error);
			if (env->last_ret != 0)
				return (sh_exec_pipe(env, tree, root->right));
		}
		else
		{
			return (sh_exec_pipe(env, tree, root));
		}
	}
	return (error);
}

int		sh_exec_semi(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root)
{
	t_sh_command		*cmd;
	int					error;

	error = 1;
	if (root)
	{
		error = 0;
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_SEMICOLON)
		{
			if ((error = sh_exec_log(env, tree, root->left)))
				return (error);
			if ((error = sh_exec_semi(env, tree, root->right)))
				return (error);
		}
		else
		{
			return (sh_exec_log(env, tree, root));
		}
	}
	return (error);
}

int		sh_exec(t_sh_env *env, t_ckbt *tree)
{
	return (sh_exec_semi(env, tree, tree->root));
}

int		main(int argc, const char **argv)
{
	t_sh_env		env;
	int				error;
	t_ckbt			*tree;
	t_cks			line;

	if (sh_init_env(&env, argc, argv) == 0)
	{
		while ((line = cks_get_line(0)) != NULL)
		{
			tree = ckbt_new(t_sh_command);
			error = sh_parse(line, tree, "./");
			ckbt_debug(tree, debug_tree);
			printf("cmd ran OK: %d\n", sh_exec(&env, tree));
			cks_free(line);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:11:02 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/19 16:41:04 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int		sh_init_env_get_base(const char *prog, t_cks *base)
{
	char		*path;
	t_cks		dir;

	if (prog[0] == '/' || (prog[0] == '.' && prog[1] == '/')
		|| (prog[0] == '~' && prog[1] == '/'))
	{
		if ((path = getcwd(NULL, 0)) == NULL
			|| (*base = cks_new("")) == NULL
			|| (dir = ckf_dirname(prog)) == NULL
			|| (*base = cks_append(*base, path)) == NULL
			|| (*base = cks_append(*base, "/")) == NULL
			|| (*base = cks_append(*base, dir)) == NULL)
			return (1);
		cks_free(dir);
		free(path);
		return (0);
	}
	if ((*base = cks_new("")) == NULL)
		return (1);
	return (0);	
}

int		sh_init_env(t_sh_env *env, int argc, const char **argv)
{
	const char	*tty;

	if (argc < 1 || argv == NULL || argv[0] == NULL)
		return (1);
	if ((tty = ttyname(0)) == NULL
		|| (env->tty_fd = open(tty, O_WRONLY) == -1))
		return (1);
	if (sh_init_env_get_base(argv[0], &env->base))
		return (1);
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
	t_sh_command		*cmd;
	t_ckl_item			*cmd_item;
	t_ckl_item			*item;

	command = &ckbt_data(t_sh_command, node);
	dprintf(2, "%s : ", types[command->type]);
	if (command->argv)
	{
		dprintf(2, " in =>  %s ", command->in);
		dprintf(2, " out =>  %s ", command->out);
		item = command->argv->first;
		while (item)
		{
			dprintf(2, " [ %s ] ", ckl_data(t_cks, item));
			item = item->next;
		}
	}
	if (command->commands)
	{
		cmd_item = command->commands->first;
		while (cmd_item)
		{
			dprintf(2, "COMMAND => ");
			cmd = &ckl_data(t_sh_command, cmd_item);
			dprintf(2, " in =>  %s ", cmd->in);
			dprintf(2, " out =>  %s ", cmd->out);
			if (cmd->argv)
			{
				item = cmd->argv->first;
				while (item)
				{
					dprintf(2, " [ %s ] ", ckl_data(t_cks, item));
					item = item->next;
				}
			}
			dprintf(2, " // ");
			cmd_item = cmd_item->next;
		}
	}
	dprintf(2, "\n");
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

t_cks	sh_full_prog_from_path(t_cks full)
{
	const char	*path;
	t_cks		cur;
	t_ckl		*parts;
	t_ckl_item	*item;

	if ((path = getenv("PATH")) == NULL
		|| (parts = cks_split(path, ":", 0)) == NULL)
		return (NULL);
	item = parts->first;
	while (item)
	{
		cur = cks_dup(full);
		cur = cks_prepend(cur, "/");
		cur = cks_prepend(cur, ckl_data(t_cks, item));
		if (ckf_access(cur, X_OK) == 0)
			return (cur);
		cks_free(cur);
		item = item->next;
	}
	return (NULL);
}

t_cks	sh_full_prog(t_cks prog)
{
	t_cks		full;
	const char	*home;

	if ((full = cks_dup(prog)) == NULL)
		return (NULL);
	if (full[0] == '~' && full[1] == '/')
		if ((home = getenv("HOME")) == NULL
			|| (full = cks_sub(full, 1)) == NULL
			|| (full = cks_prepend(full, home)) == NULL)
			return (NULL);
	if (full[0] == '/' || (full[0] == '.' && full[1] == '/'))
		return (full);
	return (sh_full_prog_from_path(full));
}

/*
** This MUST run in a fork, or else it will
** take over the current process.
*/
int		sh_execve(t_sh_command *cmd)
{
	t_cks		*argv;
	t_cks		full_prog;

	argv = sh_get_argv(cmd);
	// handle errors with appropriate message
	if (argv == NULL || argv[0] == NULL || (full_prog = sh_full_prog(argv[0])) == NULL)
	{
		printf("42sh: command not found\n");
		exit(1);
	}
	execve(full_prog, argv, environ);
	printf("execve failed with %s / %s\n", argv[0], full_prog);
	exit(1);
}

int		sh_heredoc(t_sh_command *cmd)
{
	t_cks		line;
	int			has_stop;
	int			fd;

	if (cmd->in == NULL || cmd->in_is_heredoc == 0)
		return (0);
	fd = open("/tmp/42sh-heredoc", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd != -1)
	{
		has_stop = 0;
		while ((line = cks_get_line(0)) != NULL)
		{
			if (cks_cmp_len(cmd->in, line, cks_len(line)) == 0)
			{
				has_stop = 1;
				break ;
			}
			write(fd, line, cks_len(line));
			write(fd, "\n", 1);
		}
		if (has_stop)
		{
			close(fd);
			if ((fd = open("/tmp/42sh-heredoc", O_RDONLY)) != -1)
				dup2(fd, 0);
		}
	}
	return (1);
}

int		sh_infile(t_sh_command *cmd)
{
	int		fd;

	if (cmd->in == NULL || cmd->in_is_heredoc == 1)
		return (0);
	fd = open(cmd->in, O_RDONLY);
	if (fd != -1)
	{
		dup2(fd, 0);
		return (0);
	}
	return (1);
}

int		sh_outfile(t_sh_command *cmd)
{
	int		fd;

	if ((fd = open(cmd->out, O_WRONLY | O_CREAT | ((cmd->out_append) ? O_APPEND : O_TRUNC), 0777)) != -1)
	{
		close(1);
		dup2(fd, 1);
	}
	return (1);
}

/*
** format: arg [arg]*
** where arg is a string
*/
int		sh_exec_cmd(t_sh_env *env, t_sh_command *cmd)
{
	pid_t		pid;
	int			stat;

	pid = fork();
	if (pid == 0)
	{
		sh_heredoc(cmd);
		sh_infile(cmd);
		sh_outfile(cmd);
		sh_execve(cmd);
	}
	else if (pid > 0)
	{
		waitpid(pid, &stat, 0);
		env->last_ret = (WIFEXITED(stat)) ? WEXITSTATUS(stat) : 1;
	}
	return (0);
}

int		sh_exec_pipe_cmd(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root)
{
	pid_t			pid;
	int				fd[2];
	t_sh_command	*cmd;

	if (root)
	{
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_PIPE)
		{
			if (!root->left || !root->right)
				return (1);
			if (pipe(fd) != -1 && (pid = fork()) != -1)
			{
				if (pid == 0)
				{
					close(1);
					close(fd[0]);
					if (dup2(fd[1], 1) != -1)
					{
						cmd = &ckbt_data(t_sh_command, root->left);
						sh_heredoc(cmd);
						sh_infile(cmd);
						sh_outfile(cmd);
						sh_execve(cmd);
					}
					exit(1);
				}
				else
				{
					close(0);
					close(fd[1]);
					if (dup2(fd[0], 0) != -1)
						return (sh_exec_pipe_cmd(env, tree, root->right));
					return (2);
				}
			}
		}
		else if (cmd->type == SH_COMMAND_TYPE_EXEC)
		{
			sh_exec_cmd(env, cmd);
		}
	}
	return (1);
}

int		sh_exec_pipe(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root)
{
	t_sh_command		*cmd;

	if (root)
	{
		cmd = &ckbt_data(t_sh_command, root);
		if (cmd->type == SH_COMMAND_TYPE_EXEC)
		{
			return (sh_exec_cmd(env, cmd));
		}
		else if (cmd->type == SH_COMMAND_TYPE_PIPE)
		{
			if (fork() == 0)
				exit(sh_exec_pipe_cmd(env, tree, root));
			else
				wait(NULL);
			return (0);
		}
		return (3);
	}
	return (1);
}

int		sh_exec_log(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root)
{
	t_sh_command		*cmd;
	int					error;

	if (root)
	{
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
	return (1);
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
		write(1, "$> ", 3);
		while ((line = cks_get_line(0)) != NULL)
		{
			tree = ckbt_new(t_sh_command);
			error = sh_parse(line, tree, env.base);
			ckbt_debug(tree, debug_tree);
			if (!error)
				printf("status: %d\n", sh_exec(&env, tree));
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

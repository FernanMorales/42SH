/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:41:19 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/19 10:43:51 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H

# define SH42_H

# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include "ckl.h"
# include "cks.h"
# include "ckbt.h"
# include "ckstd.h"
# include "sh_parser.h"
# include "ckf.h"

typedef struct				s_sh_env
{
	t_cks					base;
	int						last_ret;
	int						tty_fd;
}							t_sh_env;

typedef struct				s_sh_process
{
	pid_t					pid;
	t_sh_command			*cmd;
}							t_sh_process;

typedef int		(*t_sh_builtin_func)(t_sh_env *, t_sh_command *);

typedef struct				s_sh_builtin
{
	const char				*name;
	t_sh_builtin_func		func;
}							t_sh_builtin;

extern t_sh_builtin	sh_builtin[];
extern char	**environ;

int				sh_init_env_get_base(const char *prog, t_cks *base);
int				sh_init_env(t_sh_env *env, int argc, const char **argv);
void			debug_tree(t_ckbt *tree, t_ckbt_node *node);
t_cks			*sh_get_argv(t_sh_command *cmd);
t_cks			sh_full_prog_from_path(t_cks full);
t_cks			sh_full_prog(t_cks prog);
int				sh_execve(t_sh_command *cmd);
int				sh_heredoc(t_sh_command *cmd);
int				sh_dup_heredoc(t_sh_command *cmd);
int				sh_dup_infile(t_sh_command *cmd);
int				sh_dup_outfile(t_sh_command *cmd);
int				sh_dup(t_sh_command *cmd);
int				sh_exec_cmd(t_sh_env *env, t_sh_command *cmd);
int				sh_exec_pipe_routine(t_sh_env *env, t_sh_command *cmd);
int				sh_exec_pipe(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root);
int				sh_exec_log(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root);
int				sh_exec_semi(t_sh_env *env, t_ckbt *tree, t_ckbt_node *root);
int				sh_exec(t_sh_env *env, t_ckbt *tree);
t_sh_builtin	*sh_cmd_to_builtin(t_sh_command *cmd);
int				sh_preprocess_cmd(t_sh_env *env, t_sh_command *cmd);
int				sh_builtin_cd(t_sh_env *env, t_sh_command *cmd);

/*
** Environment.
*/
void			ms_environ_clear(void);
char			**ms_environ_clone(void);
void			ms_environ_copy(void);
void			ms_environ_free(void);
void			ms_environ_print(char **env);

#endif

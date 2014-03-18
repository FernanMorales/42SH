/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 09:44:06 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/27 19:56:48 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_H
# define FTSH_H
# include <string.h>
# include <sys/types.h>
# include "./libft/libft.h"

# define BUFF_SIZE 90960

typedef struct		s_list
{
	char			**content;
	struct s_list	*next;
}					t_list;

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_env
{
	int				status;
	int				process;
	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
	pid_t			father;
	char			*data;
	char			*caca;
	char			*cmd1;
	char			*cmd;
	char			**var;
	char			**lib;
	char			**test;
	char			*home;
	char			*pwd;
	char			*env_args;
	char			**env;
	char			**buf;
	t_list			*lst;
}					t_env;

int					main(void);
int					get_next_line(int const fd, char **line);
void				print_header(void);
void				print_cderror(char *var, int i);
void				treat_case(char **var, t_env *e);
void				print_env(char **env);
char				*test_cmd(char **lib, char *var, int i);
char				**copy_env(char **env, char **environ);
void				set_env(t_env *e, char **var);
void				unset_env(t_env *e, char **var);
void				print_prompt(t_env e);
void				exec_cmd(t_env *e, char **content);
void				treat_pipe(t_env *e, char **str);
void				start_father(char **av, int *fds, t_env *e);
void				start_child(char **av, int *fds, t_env *e);
int					check_pipe(char **str);
char				**trim2(char **str);
char				**trim(char **str);
int					stock_cmd(t_list **s, char *data, pid_t *father, t_env e);
void				addnode(t_list **s, char **name);
int					check_builtin(char **var, pid_t father);
int					count_str(char **tab);
void				print_env(char **env);
void				print_cmd(t_list *lst);
void				free_tab(char **tab);

#endif

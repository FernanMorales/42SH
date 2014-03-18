/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 16:20:57 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/15 22:18:44 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include <termios.h>
# include <stdlib.h>
# define K_AR_L "\033\133\104\0\0\0\0\0"
# define K_AR_U "\033\133\101\0\0\0\0\0"
# define K_AR_R "\033\133\103\0\0\0\0\0"
# define K_AR_D "\033\133\102\0\0\0\0\0"
# define K_HOME 4741915
# define K_CTRL_A
# define K_END 4610843
# define K_CTRL_E
# define K_TAB 9
# define K_PREV 5263131
# define K_NEXT 5328667
# define K_CTRL_D "\4\0\0\0\0\0\0\0"
# define K_CTRL_L "\14\0\0\0\0\0\0\0"
# define K_DEL_L "\177\0\0\0\0\0\0\0"
# define K_DEL_R "\033\133\063\176\0\0\0\0"
# define K_RETURN "\012\0\0\0\0\0\0\0"
# define K_ECHAP 27
# define PROMPT "42sh > "

enum				e_error
{
	ERROR_INIT,
	ERROR_CLOSE
};

enum				e_exit
{
	EXIT,
	ESC
};

typedef struct		s_elem
{
	char				data;
	struct s_elem		*next;
	struct s_elem		*prev;
}					t_elem;

typedef struct		s_lst
{
	t_elem			*first;
	t_elem			*last;
	t_elem			*cursor;
	int				size_lst;
	struct s_lst	**histo;
	char			*str_return;
}					t_lst;


typedef struct		s_env
{
	char			buf[5];
	char			**env_c;
	struct termios	term;
	struct termios	term_origin;
	struct winsize	term_size;
	int				fd_tty;
//	t_lst			l;
}					t_env;

void		init_env(t_env *e, char **envp);

/*
** Term
*/
void		init_term(t_env *e);
void		close_term(t_env *e);
/*
** list
*/
t_lst		*init_list(void);
t_elem		*creat_elem(char data);
void		insert_top(t_lst *l, char data);
void		insert_pos(t_lst *l, t_elem *pos, char data);
void		del_elem(t_lst *l, t_elem *cur);
/*
** lst

t_lst		*init_list(void);
int			insert_empty_lst(t_lst *l, char *data);
int			insert_elem(t_lst *l, char *data);
int			del_last_elem(t_lst *l);
void		creat_lst(t_lst *l, char **av);
void		del_elem(t_lst *l, t_elem *current);
int			insert_cur_position(t_lst *l, t_elem *cur, const char *data);
int			insert_cur_top(t_lst *l, char *data);
*/
/*
** ft_signal
*/
void		signal_handler(int sig);

/*
** print
*/
int			tputs_putchar(int c);
void		ft_print(char **line);
void		reset_cursor(int len);
void		print_lst(t_lst *l);
void		print_prompt(void);

/*
** mov_functions & mov_funct_?
*/
void	move_left(t_lst *l);
void	move_right(t_lst *l);
void	move_up(t_lst *l);
void	move_down(t_lst *l);
void	save_in_string(t_lst *l);
void	del_one(t_lst *l);

typedef void	(*t_funcptr_mov)(t_lst *l);
typedef struct	s_mov_functions
{
	char			*key;
	t_funcptr_mov	funct;
}				t_mov_functions;

extern const t_mov_functions	g_mov_functions[];

#endif /* !FT_TERM_H */

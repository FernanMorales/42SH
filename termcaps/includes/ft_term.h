/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 16:20:57 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/07 15:18:47 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include <termios.h>
# include <stdlib.h>
# define K_AR_L "\33\133\104\0\0\0\0\0"
# define K_AR_U "\33\133\101\0\0\0\0\0"
# define K_AR_R "\33\133\103\0\0\0\0\0"
# define K_AR_D "\33\133\102\0\0\0\0\0"
# define K_HOME 4741915
# define K_CTRL_A
# define K_END 4610843
# define K_CTRL_E
# define K_TAB 9
# define K_PREV 5263131
# define K_NEXT 5328667
# define K_CTRLD "\4\0\0\0\0\0\0\0"
# define K_DEL_L "\177\0\0\0\0\0\0\0"
# define K_DEL_R "\176\0\0\0\0\0\0\0"
# define K_RETURN 10
# define K_ECHAP 27

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
	char			*data;
	int				selected;
	size_t			size_data;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_lst
{
	t_elem			*first;
	t_elem			*last;
	t_elem			*cursor;
	int				size_lst;
	struct s_lst	*cur;
//	size_t			max_size;
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
** lst
*/
void		init_list(t_lst *l);
int			insert_empty_lst(t_lst *l, char *data);
int			insert_elem(t_lst *l, char *data);
int			del_last_elem(t_lst *l);
void		creat_lst(t_lst *l, char **av);
void		del_elem(t_lst *l, t_elem *current);

/*
** ft_signal
*/
void				signal_handler(int sig);

#endif /* !FT_TERM_H */

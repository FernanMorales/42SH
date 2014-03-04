/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 16:20:57 by pvarin            #+#    #+#             */
/*   Updated: 2014/03/03 19:33:30 by pvarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include <termios.h>
# include <stdlib.h>

enum				e_error
{
	ERRRO_INIT,
	ERROR_CLOSE,
};

enum				ee_exit
{
	EXIT,
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
	size_t			max_size;
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

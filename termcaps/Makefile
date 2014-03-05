#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 18:34:11 by pvarin            #+#    #+#              #
#    Updated: 2014/03/05 15:10:42 by pvarin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		= gcc
CFLAGS	= -g -Wall -Werror -Wextra
NAME	= termcaps
SRC		= $(addprefix srcs/,$(addsuffix .c, main ft_term list ft_signal))
OBJ		= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	make -C libft/
	$(CC) $(CFLAGS) -o $@ $^ -L libft -lft -ltermcap

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I libft/includes -I ./includes

.PHONY : clean fclean re

clean :
	make -C libft/ clean
	/bin/rm -rf $(OBJ)
fclean : clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)
re : fclean all

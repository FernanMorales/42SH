#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvarin <pvarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/22 18:34:11 by pvarin            #+#    #+#              #
#    Updated: 2014/03/10 21:20:14 by pvarin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = termcaps

CFLAGS = -Werror -g
ALL_CFLAGS = -Wall -Wextra $(CFLAGS)

FILES = main ft_term print ft_signal list
FILES += mov_functions mov_funct_1

SRC = $(addprefix srcs/, $(addsuffix .c, $(FILES)))
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(MAKE) -C libft/
	$(CC) $(ALL_CFLAGS) -o $@ $^ -L libft -lft -ltermcap

%.o: %.c includes/ft_term.h
	$(CC) $(ALL_CFLAGS) -c $< -o $@ -I libft/includes -I ./includes

.PHONY: clean fclean re all
clean:
	$(MAKE) clean -C libft/
	$(RM) $(OBJ)
fclean: clean
	$(MAKE) fclean -C libft/
	$(RM) $(NAME)
re: fclean all

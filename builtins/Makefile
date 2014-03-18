# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/12 18:18:25 by fmorales          #+#    #+#              #
#    Updated: 2014/01/26 21:23:20 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MKEX = cc -g -o
SRC = 	main.c			  \
		print_header.c	  \
		print_error.c	  \
		treat_case.c	  \
		test_cmd.c		  \
		set_env.c		  \
		exec_cmd.c		  \
		check_pipe.c	  \
		stock_cmd.c		  \
	  	getnextline.c 
FLAGS = -Wall -Wextra -Werror
OBJECT = $(SRC:.c=.o)
COMP = cc -c
NAME = ft_minishell2

all : $(NAME)

$(NAME) : $(OBJECT)
		@$(MKEX) $(NAME) $(OBJECT) -L libft/ -lft
		@echo "Minishell2 Ready. Enjoy!"

$(OBJECT) :
		@make -C libft/
		@$(COMP) $(SRC) $(FLAGS) -I./ -I libft/
		@echo "Compilation of C files succesful"

clean :
		@/bin/rm -f $(OBJECT)
		@echo "Object deleted"


fclean : clean
		@/bin/rm -f $(NAME)
		@echo "Folder cleanup successful"

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckleines <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:37:01 by ckleines          #+#    #+#              #
#    Updated: 2014/03/18 11:34:49 by ckleines         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
SRC = \
	  src/debug_tree.c \
	  src/main.c \
	  src/sh_dup.c \
	  src/sh_dup_heredoc.c \
	  src/sh_dup_infile.c \
	  src/sh_dup_outfile.c \
	  src/sh_exec.c \
	  src/sh_exec_cmd.c \
	  src/sh_exec_log.c \
	  src/sh_exec_pipe.c \
	  src/sh_exec_pipe_routine.c \
	  src/sh_exec_semi.c \
	  src/sh_execve.c \
	  src/sh_full_prog.c \
	  src/sh_full_prog_from_path.c \
	  src/sh_get_argv.c \
	  src/sh_heredoc.c \
	  src/sh_init_env.c \
	  src/sh_init_env_get_base.c
OBJ = $(SRC:.c=.o)
LIB = -L ../lexer/libcks/bin -l cks \
	  -L ../lexer/libckl/bin -l ckl \
	  -L ../lexer/libckbt/bin -l ckbt \
	  -L ../lexer/libckstd/bin -l ckstd \
	  -L ../lexer -l sh_parser \
	  -L libckf/bin -l ckf
INC = -I ../lexer -I ../lexer/libcks -I ../lexer/libckl -I ../lexer/libckbt \
	  -I ../lexer/libckstd -I libckf -I .
CC = cc -g -Wall -Wextra -Werror

all: $(NAME)

libs:
	make -C ../lexer
	make -C libckf

$(NAME): $(OBJ) sh42.h libs
	$(CC) $(OBJ) -o $(NAME) $(LIB) $(INC)

%.o: %.c sh42.h libs
	$(CC) -c -o $@ $< $(INC)

clean:
	make -C ../lexer clean
	make -C libckf clean
	rm -f $(OBJ)

fclean: clean
	make -C ../lexer fclean
	make -C libckf fclean
	rm -f $(NAME)

re: fclean all

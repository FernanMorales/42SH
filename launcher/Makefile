# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckleines <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:37:01 by ckleines          #+#    #+#              #
#    Updated: 2014/03/08 11:10:22 by ckleines         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
SRC = \
	main.c
OBJ = $(SRC:.c=.o)
LIB = -L ../lexer/libcks/bin -l cks \
	  -L ../lexer/libckl/bin -l ckl \
	  -L ../lexer/libckbt/bin -l ckbt \
	  -L ../lexer/libckstd/bin -l ckstd \
	  -L ../lexer -l sh_parser \
	  -L libckf/bin -l ckf
INC = -I ../lexer -I ../lexer/libcks -I ../lexer/libckl -I ../lexer/libckbt \
	  -I ../lexer/libckstd -I libckf
CC = cc -g -Wall -Wextra -Werror

all: $(NAME)

libs:
	make -C ../lexer
	make -C libckf

$(NAME): $(OBJ) sh42.h libs
	$(CC) $(OBJ) -o $(NAME) $(LIB) $(INC)

%.o: %.c sh42.h libs
	$(CC) -c -o $@ $< $(INC)

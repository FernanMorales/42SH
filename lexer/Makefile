# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckleines <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 14:16:46 by ckleines          #+#    #+#              #
#    Updated: 2014/03/05 17:08:55 by ckleines         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsh_parser.a
LIB = -L libcks/bin -l cks -L libckl/bin -l ckl -L libckstd/bin -l ckstd \
	-L . -l sh_parser -L libckbt/bin -l ckbt
INC = -I libcks -I libckl -I libckstd -I inc -I libckbt -I .
CFLAGS = -g -Wall -Wextra -Werror
CC = cc $(CFLAGS) $(INC)
SRC = \
	src/parser.c \
	src/lexer.c \
	src/am.c \
	src/parent_checker.c
OBJ = $(SRC:.c=.o)
INCLUDES = inc/am.h inc/sh.h

.PHONY: all re fclean clean

all: $(NAME)

src/%.o: src/%.c $(INCLUDES)
	$(CC) -c -o $@ $<

$(NAME): $(OBJ) $(INCLUDES)
	make -C libckstd
	make -C libcks
	make -C libckl
	make -C libckbt
	ar -rc $(NAME) $(OBJ)

clean:
	make -C libckstd clean
	make -C libcks clean
	make -C libckl clean
	make -C libckbt clean
	rm -f $(OBJ)

fclean: clean
	make -C libckstd fclean
	make -C libcks fclean
	make -C libckl fclean
	make -C libckbt fclean
	rm -f $(NAME)
	rm -Rf $(NAME).dSYM
	rm -Rf test.dSYM

re: fclean all

test: $(NAME)
	$(CC) -o test test.c $(OBJ) $(INC) $(LIB)

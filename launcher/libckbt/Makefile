# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckleines <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 22:45:11 by ckleines          #+#    #+#              #
#    Updated: 2014/03/27 16:21:09 by ckleines         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# The MIT License (MIT)                                                        #
# Copyright © 2014 Conrad Kleinespel <conradk@conradk.com>                     #
#                                                                              #
# Permission is hereby granted, free of charge, to any person obtaining a copy #
# of this software and associated documentation files (the “Software”), to     #
# deal in the Software without restriction, including without limitation the   #
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  #
# sell copies of the Software, and to permit persons to whom the Software is   #
# furnished to do so, subject to the following conditions:                     #
#                                                                              #
# The above copyright notice and this permission notice shall be included in   #
# all copies or substantial portions of the Software.                          #
#                                                                              #
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  #
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER       #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      #
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS #
# IN THE SOFTWARE.                                                             #
# **************************************************************************** #

CC = cc ${CKBT_DEBUG} -Wall -Wextra -Werror
INC = -I . -I libckstd
LIB = -L libckstd/bin -l ckstd -L bin -l ckbt
NAME = bin/libckbt.a
HEADER = ckbt.h
SRC = \
	ckbt_new_f.c \
	ckbt_debug.c \
	ckbt_free.c \
	ckbt_free_node.c \
	ckbt_new_node.c
OBJ = $(SRC:.c=.o)

.PHONY: all all_debug clean fclean re test test_debug

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C libckstd
	ar -rc $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	make -C libckstd
	$(CC) -c -o $@ $< $(INC)

all_debug:
	CKBT_DEBUG=-g make

clean:
	make -C libckstd clean
	rm -f $(OBJ)

fclean: clean
	make -C libckstd fclean
	if [ -f $(NAME) ]; then rm $(NAME); fi
	if [ -f bin/test ]; then rm bin/test; fi

re: fclean all

test: all
	$(CC) -o bin/test test.c $(INC) $(LIB)

test_debug:
	CKBT_DEBUG=-g make test

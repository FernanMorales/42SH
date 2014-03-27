# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckleines <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 22:45:11 by ckleines          #+#    #+#              #
#    Updated: 2014/03/18 13:53:00 by ckleines         ###   ########.fr        #
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

CC = cc ${CKS_DEBUG} -Wall -Wextra -Werror
INC = -I . -I libckstd -I libckl
LIB = -L libckstd/bin -l ckstd -L bin -l cks -L libckl/bin -l ckl
NAME = bin/libcks.a
SRC = \
	cks_insert_len.c \
	cks_append.c \
	cks_append_len.c \
	cks_cmp.c \
	cks_cmp_len.c \
	cks_dup.c \
	cks_free.c \
	cks_get_line.c \
	cks_insert.c \
	cks_len.c \
	cks_len_grow.c \
	cks_malloc.c \
	cks_mem.c \
	cks_new.c \
	cks_new_len.c \
	cks_prepend.c \
	cks_prepend_len.c \
	cks_set_len.c \
	cks_set_mem.c \
	cks_sub.c \
	cks_sub_len.c \
	cks_split.c
OBJ = $(SRC:.c=.o)
HEADER = cks.h

.PHONY: all all_debug clean fclean re test test_debug

all: $(NAME)

%.o: %.c $(HEADER)
	make -C libckstd
	make -C libckl
	$(CC) -c -o $@ $< $(INC)

$(NAME): $(OBJ) $(HEADER)
	make -C libckstd
	make -C libckl
	ar -rc $(NAME) $(OBJ)

all_debug:
	CKS_DEBUG=-g make

clean:
	make -C libckstd clean
	make -C libckl clean
	rm -f $(OBJ)

fclean: clean
	make -C libckstd fclean
	make -C libckl fclean
	if [ -f $(NAME) ]; then rm $(NAME); fi
	if [ -f bin/test ]; then rm bin/test; fi

re: fclean all

test: all
	$(CC) -o bin/test test.c $(INC) $(LIB)

test_debug:
	CKS_DEBUG=-g make test

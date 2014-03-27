# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckleines <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 22:45:11 by ckleines          #+#    #+#              #
#    Updated: 2014/03/18 15:21:15 by ckleines         ###   ########.fr        #
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

CC = cc ${CKF_DEBUG} -Wall -Wextra -Werror
INC = -I . -I libckstd -I libcks -I libcks/libckl
LIB = -L libckstd/bin -l ckstd -L libcks/bin -l cks -L bin -l ckf
NAME = bin/libckf.a
SRC = \
	ckf_dirname.c \
	ckf_access.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C libckstd
	make -C libcks
	ar -rc $(NAME) $(OBJ)

clean:
	make -C libckstd clean
	rm -f $(OBJ)

%.o: %.c $(HEADER)
	make -C libckstd
	make -C libcks
	$(CC) -c -o $@ $< $(INC)

fclean: clean
	make -C libckstd fclean
	rm -f $(NAME)
	rm -f bin/test

re: fclean all

test: all
	$(CC) -o bin/test test.c $(INC) $(LIB)

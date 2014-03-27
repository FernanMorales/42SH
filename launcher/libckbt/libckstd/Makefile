# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckleines <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 22:45:11 by ckleines          #+#    #+#              #
#    Updated: 2014/03/25 17:35:28 by ckleines         ###   ########.fr        #
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

NAME = bin/libckstd.a
CC = cc ${CKSTD_DEBUG} -Wall -Wextra -Werror
SRC = \
	ckstd_memcmp.c \
	ckstd_memcpy.c \
	ckstd_memmove.c \
	ckstd_strcmp.c \
	ckstd_strlen.c \
	ckstd_strdup.c \
	ckstd_strncmp.c \
	ckstd_atoi.c \
	ckstd_strchr.c
OBJ = $(SRC:.c=.o)
HEADER = ckstd.h

.PHONY: all all_debug clean fclean re

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $<

$(NAME): $(OBJ) $(HEADER)
	ar -rc $(NAME) $(OBJ)

all_debug:
	CKSTD_DEBUG=-g make

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

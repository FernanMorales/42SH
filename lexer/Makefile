# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckleines <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 14:16:46 by ckleines          #+#    #+#              #
#    Updated: 2014/03/06 17:32:29 by ckleines         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsh_parser.a
LIB = -L libcks/bin -l cks -L libckl/bin -l ckl -L libckstd/bin -l ckstd \
	-L . -l sh_parser -L libckbt/bin -l ckbt
INC = -I libcks -I libckl -I libckstd -I inc -I libckbt -I .
CFLAGS = -g -Wall -Wextra -Werror
CC = cc $(CFLAGS) $(INC)
SRC = \
	  src/am.c \
	  src/am_lex.c \
	  src/is_not_meaningful.c \
	  src/lexer_automaton_command_line_token.c \
	  src/lexer_automaton_double_quote_string.c \
	  src/lexer_automaton_single_quote_string.c \
	  src/lexer_automaton_string.c \
	  src/lexer_callback_double_quote_string_content.c \
	  src/lexer_callback_single_quote_string_content.c \
	  src/lexer_callback_string.c \
	  src/parent_checker.c \
	  src/parser.c \
	  src/sh_build_tree.c \
	  src/sh_concat_strings.c \
	  src/sh_heredoc.c \
	  src/sh_infile.c \
	  src/sh_lex.c \
	  src/sh_outfile.c \
	  src/sh_outfile_append.c \
	  src/sh_parse.c \
	  src/sh_print_tokens.c \
	  src/sh_remove_useless_tokens.c \
	  src/sh_remove_whitespace.c \
	  src/sh_replace_redirections.c \
	  src/sh_replace_redirections_in.c \
	  src/sh_replace_redirections_out.c \
	  src/sh_token_is_quoted_string.c \
	  src/sh_token_is_string.c \
	  src/sh_type_is_op.c

OBJ = $(SRC:.c=.o)
INCLUDES = inc/am.h inc/sh.h

.PHONY: all re fclean clean

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	make -C libckstd
	make -C libcks
	make -C libckl
	make -C libckbt
	ar -rc $(NAME) $(OBJ)

src/%.o: src/%.c $(INCLUDES)
	$(CC) -c -o $@ $<

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

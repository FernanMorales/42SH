# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckleines <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 14:16:46 by ckleines          #+#    #+#              #
#    Updated: 2014/03/08 10:02:08 by ckleines         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsh_parser.a
LIB = -L libcks/bin -l cks -L libckl/bin -l ckl -L libckstd/bin -l ckstd \
	-L . -l sh_parser -L libckbt/bin -l ckbt
INC = -I libcks -I libckl -I libckstd -I inc -I libckbt -I .
CFLAGS = -g -Wall -Wextra -Werror
CC = cc $(CFLAGS) $(INC)
SRC = \
	  src/am_add_token.c \
	  src/am_callback_is_end.c \
	  src/am_callback_is_not_whitespace.c \
	  src/am_find_automaton.c \
	  src/am_find_callback.c \
	  src/am_find_end.c \
	  src/am_find_string.c \
	  src/am_find_whitespace.c \
	  src/am_finder_automaton.c \
	  src/am_finder_string.c \
	  src/am_free.c \
	  src/am_free_finder_content.c \
	  src/am_free_token_content.c \
	  src/am_lex.c \
	  src/am_make_whitespace_automaton.c \
	  src/am_new.c \
	  src/am_ok.c \
	  src/am_reset.c \
	  src/am_run.c \
	  src/am_sub_free.c \
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
	  src/sh_group_pipe_subcommands.c \
	  src/sh_group_pipe_subcommands_do.c \
	  src/sh_has_arg.c \
	  src/sh_has_redirection.c \
	  src/sh_heredoc.c \
	  src/sh_infile.c \
	  src/sh_lex.c \
	  src/sh_new_node_logic.c \
	  src/sh_new_node_pipe.c \
	  src/sh_new_node_semicolon.c \
	  src/sh_new_node_string.c \
	  src/sh_outfile.c \
	  src/sh_outfile_append.c \
	  src/sh_parse.c \
	  src/sh_parse_actual_log_cmd.c \
	  src/sh_parse_arg.c \
	  src/sh_parse_cmd.c \
	  src/sh_parse_cmd_line.c \
	  src/sh_parse_log_cmd.c \
	  src/sh_parse_num_log_ops.c \
	  src/sh_parse_pipe_cmd.c \
	  src/sh_parse_redirection.c \
	  src/sh_parse_seq_cmd.c \
	  src/sh_print_tokens.c \
	  src/sh_remove_useless_tokens.c \
	  src/sh_remove_whitespace.c \
	  src/sh_token_is_quoted_string.c \
	  src/sh_token_is_string.c \
	  src/sh_type_is_op.c

OBJ = $(SRC:.c=.o)
INCLUDES = inc/am.h inc/sh.h

.PHONY: all re fclean clean

all: $(NAME)

libs:
	make -C libckstd
	make -C libcks
	make -C libckl
	make -C libckbt

$(NAME): $(OBJ) $(INCLUDES) libs
	ar -rc $(NAME) $(OBJ)

src/%.o: src/%.c $(INCLUDES) libs
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

test: $(NAME) test.c
	$(CC) -o test test.c $(OBJ) $(INC) $(LIB)

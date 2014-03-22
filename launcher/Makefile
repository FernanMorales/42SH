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
	  src/debug_tree.c \
	  src/is_not_meaningful.c \
	  src/lexer_automaton_command_line_token.c \
	  src/lexer_automaton_double_quote_string.c \
	  src/lexer_automaton_single_quote_string.c \
	  src/lexer_automaton_string.c \
	  src/lexer_callback_double_quote_string_content.c \
	  src/lexer_callback_single_quote_string_content.c \
	  src/lexer_callback_string.c \
	  src/main.c \
	  src/parent_checker.c \
	  src/parser.c \
	  src/sh_build_tree.c \
	  src/sh_concat_strings.c \
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
	  src/sh_group_pipe_subcommands.c \
	  src/sh_group_pipe_subcommands_do.c \
	  src/sh_has_arg.c \
	  src/sh_has_redirection.c \
	  src/sh_heredoc.c \
	  src/sh_infile.c \
	  src/sh_init_env.c \
	  src/sh_init_env_get_base.c \
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
LIB = -L libcks/bin -l cks \
	  -L libckl/bin -l ckl \
	  -L libckbt/bin -l ckbt \
	  -L libckstd/bin -l ckstd \
	  -L libckf/bin -l ckf
INC = -I libcks -I libckl -I libckbt \
	  -I libckstd -I libckf -I . -I inc
CC = cc -g -Wall -Wextra -Werror
HEADERS = sh42.h sh_parser.h inc/am.h inc/sh.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	make -C libcks
	make -C libckbt
	make -C libckl
	make -C libckstd
	make -C libckf
	$(CC) $(OBJ) -o $(NAME) $(LIB) $(INC)

%.o: %.c $(HEADERS)
	make -C libcks
	make -C libckbt
	make -C libckl
	make -C libckstd
	make -C libckf
	$(CC) -c -o $@ $< $(INC)

clean:
	make -C libcks clean
	make -C libckbt clean
	make -C libckl clean
	make -C libckstd clean
	make -C libckf clean
	rm -f $(OBJ)

fclean: clean
	make -C libcks fclean
	make -C libckbt fclean
	make -C libckl fclean
	make -C libckstd fclean
	make -C libckf fclean
	rm -f $(NAME)

re: fclean all

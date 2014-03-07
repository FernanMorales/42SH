/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 01:54:15 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/07 01:55:01 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H

# define SH_PARSER_H

# include "ckbt.h"
# include "ckl.h"

/*
** error codes:
** bad allocation => < -1
** syntax         => -1
** bracketing     => > 0, see below
** no error       => 0
*/

/*
** command substitution
** double quotes
** single quotes
** back ticks
*/
# define SH_PARENT_CHECK_TYPE_CS (1)
# define SH_PARENT_CHECK_TYPE_DQ (2)
# define SH_PARENT_CHECK_TYPE_SQ (3)
# define SH_PARENT_CHECK_TYPE_BT (4)

typedef enum					e_sh_token_type
{
	SH_TOKEN_TYPE_SINGLE_QUOTE,
	SH_TOKEN_TYPE_SINGLE_QUOTE_STRING,
	SH_TOKEN_TYPE_DOUBLE_QUOTE,
	SH_TOKEN_TYPE_DOUBLE_QUOTE_STRING,
	SH_TOKEN_TYPE_STRING,
	SH_TOKEN_TYPE_WHITESPACE,
	SH_TOKEN_TYPE_SEMICOLON,
	SH_TOKEN_TYPE_LOGICAL_AND,
	SH_TOKEN_TYPE_LOGICAL_OR,
	SH_TOKEN_TYPE_REDIR_IN,
	SH_TOKEN_TYPE_REDIR_OUT,
	SH_TOKEN_TYPE_APPEND_REDIR_OUT,
	SH_TOKEN_TYPE_HERE_DOC,
	SH_TOKEN_TYPE_PIPE,
	SH_TOKEN_TYPE_BACKGROUND,
	SH_TOKEN_TYPE_EXCLAMATION_POINT,
	SH_TOKEN_TYPE_SUBCOMMAND,
	SH_TOKEN_TYPE_SUBCOMMAND_BORDER,
	SH_TOKEN_TYPE_QUOTE_STRING
}								t_sh_token_type;

typedef enum					e_sh_command_type
{
	SH_COMMAND_TYPE_PIPE,
	SH_COMMAND_TYPE_AND,
	SH_COMMAND_TYPE_OR,
	SH_COMMAND_TYPE_SEMICOLON,
	SH_COMMAND_TYPE_EXEC
}								t_sh_command_type;

typedef struct					s_sh_command
{
	t_sh_command_type			type;
	t_ckl						*argv;
}								t_sh_command;

extern char						*sh_types[19];

/*
** Base is the basepath of the executable ./42sh.
** It is used to deduce the paths of 42heredoc, 42out, 42in and 42outappend.
*/
int			sh_parse(const char *src, t_ckbt *tree, const char *base);
int			sh_lex(const char *src, t_ckl *tokens);
int			sh_check_bracketing(const char *src);

#endif

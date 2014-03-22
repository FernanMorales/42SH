/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckleines <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 17:31:36 by ckleines          #+#    #+#             */
/*   Updated: 2014/03/06 17:31:37 by ckleines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ckl.h"
#include "am.h"
#include "sh.h"

char	*sh_types[19] = {
	"SINGLE_QUOTE",
	"SINGLE_QUOTE_STRING",
	"DOUBLE_QUOTE",
	"DOUBLE_QUOTE_STRING",
	"STRING",
	"WHITESPACE",
	"SEMICOLON",
	"LOGICAL_AND",
	"LOGICAL_OR",
	"REDIR_IN",
	"REDIR_OUT",
	"APPEND_REDIR_OUT",
	"HERE_DOC",
	"PIPE",
	"BACKGROUND",
	"EXCLAMATION_POINT",
	"SUBCOMMAND",
	"SUBCOMMAND_BORDER",
	"QUOTE_STRING"
};

#include "ckl.h"
#include "am.h"
#include "sh_parser.h"

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

void		sh_print_tokens(t_ckl *tokens)
{
	t_ckl_item	*item;

	item = tokens->first;
	while (item)
	{
		t_am_token	*token = &ckl_data(t_am_token, item);
		printf("%s => `%s`\n", sh_types[token->type], token->value_computed);
		item = item->next;
	}
}

int			sh_build_tree(t_ckl *tokens, t_ckbt *tree)
{
	tokens = NULL;
	tree = NULL;
	return (0);
}

int			sh_parse(const char *src, t_ckbt *tree)
{
	t_ckl	*tokens;
	int		brackets;

	if ((brackets = sh_check_bracketing(src)) != 0)
		return (brackets);
	if ((tokens = ckl_new(t_am_token)) == NULL)
		return (-2);
	if (sh_lex(src, tokens) != 0)
		return (-1);
	sh_print_tokens(tokens);
	sh_build_tree(tokens, tree);
	return (0);
}

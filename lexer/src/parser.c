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

void	sh_infile(t_ckl *tokens, t_ckl_item *start, const t_cks file, const char *base)
{
	t_am_token		one;
	t_am_token		two;
	t_am_token		three;

	one.type = SH_TOKEN_TYPE_STRING;
	one.value_orig = cks_append(cks_new(base), "42sh-infile");
	one.value_computed = cks_append(cks_new(base), "42sh-infile");
	two.type = SH_TOKEN_TYPE_STRING;
	two.value_orig = cks_dup(file);
	two.value_computed = cks_dup(file);
	three.type = SH_TOKEN_TYPE_PIPE;
	three.value_orig = cks_new("|");
	three.value_computed = cks_new("|");
	ckl_prepend_item(tokens, start, &one);
	ckl_prepend_item(tokens, start, &two);
	ckl_prepend_item(tokens, start, &three);
}

void	sh_heredoc(t_ckl *tokens, t_ckl_item *start, const t_cks boundary, const char *base)
{
	t_am_token		one;
	t_am_token		two;
	t_am_token		three;

	one.type = SH_TOKEN_TYPE_STRING;
	one.value_orig = cks_append(cks_new(base), "42sh-heredoc");
	one.value_computed = cks_append(cks_new(base), "42sh-heredoc");
	two.type = SH_TOKEN_TYPE_STRING;
	two.value_orig = cks_dup(boundary);
	two.value_computed = cks_dup(boundary);
	three.type = SH_TOKEN_TYPE_PIPE;
	three.value_orig = cks_new("|");
	three.value_computed = cks_new("|");
	ckl_prepend_item(tokens, start, &one);
	ckl_prepend_item(tokens, start, &two);
	ckl_prepend_item(tokens, start, &three);
}

void	sh_replace_redirections_in(t_ckl *t, t_ckl_item *start, const char *base)
{
	t_ckl_item		*i;
	t_am_token		*curr;
	t_am_token		*next;

	i = start;
	while (i && i->next)
	{
		next = &ckl_data(t_am_token, i->next);
		curr = &ckl_data(t_am_token, i);
		if (curr->type == SH_TOKEN_TYPE_REDIR_IN
			&& sh_token_is_string(next))
		{
			sh_infile(t, start, next->value_computed, base);
			ckl_withdraw(t, i);
			ckl_withdraw(t, i->next);
			i = i->next->next;
			continue ;
		}
		else if (curr->type == SH_TOKEN_TYPE_HERE_DOC
			&& sh_token_is_string(next))
		{
			sh_heredoc(t, start, next->value_computed, base);
			ckl_withdraw(t, i);
			ckl_withdraw(t, i->next);
			i = i->next->next;
			continue ;
		}
		i = i->next;
	}
}

void	sh_outfile(t_ckl *tokens, t_ckl_item *end, const t_cks file, const char *base)
{
	t_am_token		one;
	t_am_token		two;
	t_am_token		three;

	one.type = SH_TOKEN_TYPE_STRING;
	one.value_orig = cks_append(cks_new(base), "42sh-outfile");
	one.value_computed = cks_append(cks_new(base), "42sh-outfile");
	two.type = SH_TOKEN_TYPE_STRING;
	two.value_orig = cks_dup(file);
	two.value_computed = cks_dup(file);
	three.type = SH_TOKEN_TYPE_PIPE;
	three.value_orig = cks_new("|");
	three.value_computed = cks_new("|");
	ckl_append_item(tokens, end, &three);
	ckl_append_item(tokens, end->next, &one);
	ckl_append_item(tokens, end->next->next, &two);
}

void	sh_outfile_append(t_ckl *tokens, t_ckl_item *end, const t_cks boundary, const char *base)
{
	t_am_token		one;
	t_am_token		two;
	t_am_token		three;

	one.type = SH_TOKEN_TYPE_STRING;
	one.value_orig = cks_append(cks_new(base), "42sh-outfile-append");
	one.value_computed = cks_append(cks_new(base), "42sh-outfile-append");
	two.type = SH_TOKEN_TYPE_STRING;
	two.value_orig = cks_dup(boundary);
	two.value_computed = cks_dup(boundary);
	three.type = SH_TOKEN_TYPE_PIPE;
	three.value_orig = cks_new("|");
	three.value_computed = cks_new("|");
	ckl_append_item(tokens, end, &three);
	ckl_append_item(tokens, end->next, &one);
	ckl_append_item(tokens, end->next->next, &two);
}

void	sh_replace_redirections_out(t_ckl *t, t_ckl_item *start, t_ckl_item *end, const char *base)
{
	t_ckl_item		*i;
	t_am_token		*curr;
	t_am_token		*next;

	i = start;
	while (i && i->next)
	{
		next = &ckl_data(t_am_token, i->next);
		curr = &ckl_data(t_am_token, i);
		if (curr->type == SH_TOKEN_TYPE_REDIR_OUT
			&& sh_token_is_string(next))
		{
			sh_outfile(t, end, next->value_computed, base);
			ckl_withdraw(t, i);
			ckl_withdraw(t, i->next);
			i = i->next->next;
			continue ;
		}
		else if (curr->type == SH_TOKEN_TYPE_APPEND_REDIR_OUT
			&& sh_token_is_string(next))
		{
			sh_outfile_append(t, end, next->value_computed, base);
			ckl_withdraw(t, i);
			ckl_withdraw(t, i->next);
			i = i->next->next;
			continue ;
		}
		i = i->next;
	}
}

void	sh_replace_redirections(t_ckl *t, const char *base)
{
	t_ckl_item		*i;
	t_ckl_item		*start;

	i = t->first;
	while (i != NULL)
	{
		while (i && sh_type_is_op(ckl_data(t_am_token, i).type))
			i = i->next;
		if ((start = i))
			sh_replace_redirections_in(t, start, base);
		while (i && i->next && !sh_type_is_op(ckl_data(t_am_token, i->next).type))
			i = i->next;
		if (i)
			sh_replace_redirections_out(t, start, i, base);
		if (i)
			i = i->next;
	}
}

int			sh_parse(const char *src, t_ckbt *tree, const char *basepath)
{
	t_ckl	*tokens;
	int		brackets;

	if ((brackets = sh_check_bracketing(src)) != 0)
		return (brackets);
	if ((tokens = ckl_new(t_am_token)) == NULL)
		return (-2);
	if (sh_lex(src, tokens) != 0)
		return (-1);
	sh_replace_redirections(tokens, basepath);
	sh_print_tokens(tokens);
	sh_build_tree(tokens, tree);
	return (0);
}

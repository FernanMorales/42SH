#include "sh.h"

int			sh_has_arg(t_ckl *tokens)
{
	t_am_token	*tok;

	if (tokens->first == NULL)
		return (0);
	tok = &ckl_data(t_am_token, tokens->first);
	return (tok->type == SH_TOKEN_TYPE_STRING
		|| tok->type == SH_TOKEN_TYPE_QUOTE_STRING);
}

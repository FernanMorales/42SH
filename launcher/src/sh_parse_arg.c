#include "sh.h"

int			sh_parse_arg(t_ckl *tokens, t_sh_command *cmd)
{
	t_am_token	*tok;

	tok = &ckl_data(t_am_token, tokens->first);
	ckl_append(cmd->argv, &tok->value_computed);
	ckl_withdraw(tokens, tokens->first);
	return (0);
}

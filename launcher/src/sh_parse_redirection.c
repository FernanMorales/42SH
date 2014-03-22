#include "sh.h"

int			sh_parse_redirection(t_ckl *tokens, t_sh_command *cmd)
{
	t_am_token	*tok;
	t_am_token	*arg;

	tok = &ckl_data(t_am_token, tokens->first);
	arg = &ckl_data(t_am_token, tokens->first->next);
	if (tok->type == SH_TOKEN_TYPE_REDIR_IN
		|| tok->type == SH_TOKEN_TYPE_HERE_DOC)
	{
		cmd->in = arg->value_computed;
		cmd->in_is_heredoc = tok->type == SH_TOKEN_TYPE_HERE_DOC;
	}
	if (tok->type == SH_TOKEN_TYPE_REDIR_OUT
		|| tok->type == SH_TOKEN_TYPE_APPEND_REDIR_OUT)
	{
		cmd->out = arg->value_computed;
		cmd->out_append = tok->type == SH_TOKEN_TYPE_APPEND_REDIR_OUT;
	}
	ckl_withdraw(tokens, tokens->first);
	ckl_withdraw(tokens, tokens->first);
	return (0);
}

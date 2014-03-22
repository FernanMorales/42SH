#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_free_token_content(void *t)
{
	t_am_token	*token;

	token = t;
	cks_free(token->value_orig);
	cks_free(token->value_computed);
}

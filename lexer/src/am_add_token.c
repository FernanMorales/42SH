#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_add_token(t_am *am, t_cks orig, t_cks computed)
{
	t_am_token		token;
	t_cks			nsource;

	token.type = am->curr_finder->token_type;
	token.value_orig = orig;
	token.value_computed = (computed != NULL) ? computed : cks_dup(orig);
	ckl_append(am->tokens, &token);
	nsource = am->source;
	am->source = cks_sub(am->source, cks_len(orig));
	cks_free(nsource);
}

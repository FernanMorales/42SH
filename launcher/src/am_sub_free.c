#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_sub_free(t_am *am)
{
	if (am != NULL)
	{
		cks_free(am->source);
		ckl_free_items(am->tokens, NULL);
		ckl_free(am->tokens);
		ckl_free_items(am->finders, am_free_finder_content);
		ckl_free(am->finders);
		free(am);
	}
}

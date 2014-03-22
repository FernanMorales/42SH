#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_reset(t_am *am)
{
	am->tokens = NULL;
	am->state_curr = 0;
}

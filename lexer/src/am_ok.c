#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

int		am_ok(t_am *am)
{
	return (am->state_curr == am->state_final);
}

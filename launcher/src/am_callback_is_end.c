#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

int		am_callback_is_end(t_am *am)
{
	return (cks_len(am->source) == 0);
}

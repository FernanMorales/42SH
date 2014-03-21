#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_find_end(t_am *am, t_am_meta meta)
{
	am_find_callback(am, meta, am_callback_is_end);
}

#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_find_callback(t_am *am, t_am_meta meta,
			t_am_callback_finder_callback cb)
{
	t_am_finder		finder;

	finder.token_type = meta.type;
	finder.type = AM_FINDER_TYPE_CALLBACK;
	finder.join = 0;
	finder.state_prev = meta.from;
	finder.state_next = meta.to;
	finder.arg = NULL;
	finder.callback = (void *)cb;
	ckl_append(am->finders, &finder);
}

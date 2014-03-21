#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_find_automaton(t_am *am, t_am_meta meta, t_am_maker maker)
{
	t_am_finder		finder;

	finder.token_type = meta.type;
	finder.type = AM_FINDER_TYPE_AUTOMATON;
	finder.join = meta.join;
	finder.state_prev = meta.from;
	finder.state_next = meta.to;
	finder.arg = maker;
	finder.callback = (void *)am_finder_automaton;
	ckl_append(am->finders, &finder);
}

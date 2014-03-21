#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_find_whitespace(t_am *am, t_am_meta meta)
{
	meta.join = 1;
	am_find_automaton(am, meta, am_make_whitespace_automaton);
}

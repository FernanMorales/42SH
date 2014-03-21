#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

t_am	*am_make_whitespace_automaton(void)
{
	t_am		*am;

	am = am_new(2);
	am_find_string(am, am_meta(.from = 0, .to = 1), " ");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\t");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\n");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\v");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\f");
	am_find_string(am, am_meta(.from = 0, .to = 1), "\r");
	am_find_callback(am, am_meta(.from = 1, .to = 2),
		am_callback_is_not_whitespace);
	am_find_automaton(am, am_meta(.from = 1, .to = 2, .join = 0),
		am_make_whitespace_automaton);
	return (am);
}

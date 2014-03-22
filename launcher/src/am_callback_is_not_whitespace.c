#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

int		am_callback_is_not_whitespace(t_am *am)
{
	char		c;

	if (cks_len(am->source) == 0)
		return (1);
	c = am->source[0];
	return (c != ' ' && c != '\t' && c != '\n' && c != '\v' && c != '\f'
		&& c != '\r');
}

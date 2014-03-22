#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

void	am_free_finder_content(void *f)
{
	t_am_finder	*finder;

	finder = f;
	if (finder->type == AM_FINDER_TYPE_STRING)
		cks_free(finder->arg);
}

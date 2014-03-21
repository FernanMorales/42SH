#include "am.h"
#include "cks.h"
#include "ckl.h"
#include "ckstd.h"

t_am	*am_new(const int state_final)
{
	t_am		*am;

	am = (t_am *)malloc(sizeof(t_am));
	if (am == NULL)
		return (am);
	*(int *)&am->state_final = state_final;
	am->finders = ckl_new(t_am_finder);
	if (am->finders == NULL)
	{
		free(am);
		return (NULL);
	}
	am_reset(am);
	return (am);
}

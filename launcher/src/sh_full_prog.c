#include "sh42.h"

t_cks	sh_full_prog(t_cks prog)
{
	t_cks		full;
	const char	*home;

	if ((full = cks_dup(prog)) == NULL)
		return (NULL);
	if (full[0] == '~' && full[1] == '/')
		if ((home = getenv("HOME")) == NULL
			|| (full = cks_sub(full, 1)) == NULL
			|| (full = cks_prepend(full, home)) == NULL)
			return (NULL);
	if (full[0] == '/' || (full[0] == '.' && full[1] == '/'))
		return (full);
	return (sh_full_prog_from_path(full));
}

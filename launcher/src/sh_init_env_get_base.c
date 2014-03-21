#include "sh42.h"

int		sh_init_env_get_base(const char *prog, t_cks *base)
{
	char		*path;
	t_cks		dir;

	if (prog[0] == '/' || (prog[0] == '.' && prog[1] == '/')
		|| (prog[0] == '~' && prog[1] == '/'))
	{
		if ((path = getcwd(NULL, 0)) == NULL
			|| (*base = cks_new("")) == NULL
			|| (dir = ckf_dirname(prog)) == NULL
			|| (*base = cks_append(*base, path)) == NULL
			|| (*base = cks_append(*base, "/")) == NULL
			|| (*base = cks_append(*base, dir)) == NULL)
			return (1);
		cks_free(dir);
		free(path);
		return (0);
	}
	if ((*base = cks_new("")) == NULL)
		return (1);
	return (0);
}

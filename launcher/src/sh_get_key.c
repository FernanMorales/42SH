#include "sh42.h"

int			sh_get_key(char *buf)
{
	int		i;

	i = 0;
	while (sh_keys[i] != NULL)
	{
		if (ckstd_strcmp(sh_keys[i], buf) == 0)
			return (i);
		i++;
	}
	return (-1);
}

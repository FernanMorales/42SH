#include "sh42.h"

int		sh_exec(t_sh_env *env, t_ckbt *tree)
{
	return (sh_exec_semi(env, tree, tree->root));
}

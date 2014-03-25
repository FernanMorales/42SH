#include "sh42.h"

t_sh_builtin	sh_builtin[] = {
	{ "cd", NULL },//&sh_builtin_cd },
	{ "echo", NULL },
	{ "exit", NULL },
	{ "env", NULL },
	{ "setenv", NULL },
	{ "unsetenv", NULL },
	{ NULL, NULL}
};

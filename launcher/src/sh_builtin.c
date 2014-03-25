#include "sh42.h"

t_sh_builtin	sh_builtin[] = {
	{ "cd", &sh_builtin_cd },
	{ "echo", &sh_builtin_echo },
	{ "exit", NULL },
	{ "env", NULL },
	{ "setenv", NULL },
	{ "unsetenv", NULL },
	{ NULL, NULL}
};

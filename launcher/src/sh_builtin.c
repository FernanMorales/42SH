#include "sh42.h"

t_sh_builtin	sh_builtin[] = {
	{ "cd", &sh_builtin_cd },
	{ "echo", &sh_builtin_echo },
	{ "exit", &sh_builtin_exit },
	{ "env", &sh_builtin_env },
	{ "setenv", &sh_builtin_setenv },
	{ "unsetenv", &sh_builtin_unsetenv },
	{ NULL, NULL}
};

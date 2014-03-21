
/*
** This MUST run in a fork, or else it will
** take over the current process.
*/
int		sh_execve(t_sh_command *cmd)
{
	t_cks		*argv;
	t_cks		full_prog;

	argv = sh_get_argv(cmd);
	// fix better error messages
	if (argv == NULL || argv[0] == NULL || (full_prog = sh_full_prog(argv[0])) == NULL)
	{
		dprintf(2, "42sh: command not found\n");
		exit(1);
	}
	execve(full_prog, argv, environ);
	dprintf(2, "42sh: command not found\n");
	exit(1);
}

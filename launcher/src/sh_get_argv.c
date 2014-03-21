
t_cks	*sh_get_argv(t_sh_command *cmd)
{
	t_cks		*argv;
	t_ckl_item	*item;
	size_t		i;

	if (cmd == NULL || cmd->argv == NULL)
		return (NULL);
	argv = (t_cks *)malloc(sizeof(t_cks) * (cmd->argv->length + 1));
	if (argv == NULL)
		return (NULL);
	i = 0;
	item = cmd->argv->first;
	while (item)
	{
		argv[i] = ckl_data(t_cks, item);
		item = item->next;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

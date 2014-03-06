#include "sh_parser.h"
#include "ckl.h"
#include "cks.h"
#include "am.h"

int		main(void)
{
	int		error;
	t_ckbt	*tree;

	tree = ckbt_new(t_sh_command);
	error = sh_parse(cks_get_line(0), tree, "/root/dir/");
	printf("%d\n", error);
	return (error);
}

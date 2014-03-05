#include "sh_parser.h"
#include "ckl.h"
#include "cks.h"
#include "am.h"

int		main(void)
{
	int		error;

	error = sh_parse(cks_get_line(0), NULL, "/root/dir/");
	printf("%d\n", error);
	return (error);
}

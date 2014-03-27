# CKL - API

This files presents the API of the `libckl` through comprehensive examples and
code samples. Hopefully it will help you get started with the library more
quickly and less painfully! :-)

All elements of a CKL list are of the same type. This allows some nice
syntactic sugar using macros, easier manual memory management and less
memory allocations resulting in increased speed.

```c
#include <stdlib.h>
#include <string.h>
int main(void) {
	t_ckl *list = ckl_init(char *);
	ckl_append(list, strdup("Hello world!"));
	printf("%s\n", ckl_data(char *, list->first));
	ckl_free_items(list, free);
	ckl_free(list);
	return (0);
}
```

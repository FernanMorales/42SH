#include <stdlib.h>
#include <fcntl.h>

int main() {
	return (open(NULL, O_RDONLY));
}

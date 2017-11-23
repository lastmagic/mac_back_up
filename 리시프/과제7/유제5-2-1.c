#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buf[BUFSIZ];

	setbuf(stdout, buf);

	printf("Hello, "); sleep(1);
	printf("OSLAB!!"); sleep(1);
	printf("\n"); sleep(1);

	setbuf(stdout, buf);
	printf("How"); sleep(1);
	printf(" are"); sleep(1);
	printf(" you?"); sleep(1);
	printf("\n");

	exit(0);
}

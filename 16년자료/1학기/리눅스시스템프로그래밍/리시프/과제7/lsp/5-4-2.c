#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *fname = "test.txt";
	printf("First printf: Hello, OSLAB!\n");

	if((freopen(fname, "w", stdout)) != NULL)
	{
		printf("Second printf:Hello\n");
	}

	exit(0);
}

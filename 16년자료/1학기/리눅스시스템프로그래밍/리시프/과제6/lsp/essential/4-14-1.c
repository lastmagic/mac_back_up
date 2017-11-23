#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	if(chdir("/etc")<0)
	{
		printf("chdir error\n");
		exit(1);
	}

	printf("chdir to /etc succeeded\n");
	exit(0);
}

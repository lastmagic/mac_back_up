#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if((link(argv[1], argv[2]))<0)
	{
		printf("%s\n", argv[0]);
		exit(1);
	}

	exit(0);

}

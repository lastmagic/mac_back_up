#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *fname = "test.txt";
	char *mode = "r";

	if(fopen(fname, mode) == NULL)
	{
		printf("Failed\n");
		exit(1);
	}	
	else
	{
		printf("Success!\n");	
		printf("<%s>, mode: %s",fname, mode );

	}
	exit(0);
}

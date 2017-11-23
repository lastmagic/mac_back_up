#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *fname = "test.txt";
	long fsize;
	FILE *fp;

	if((fp = fopen(fname, "r")) == NULL)
	{
		printf("File open error\n");
		exit(1);
	}

	fseek(fp ,0, SEEK_END);
	fsize = ftell(fp);

	printf("The size of <%s> is %ld bytes\n", fname, fsize);
	exit(0);
}

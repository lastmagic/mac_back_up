#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;

	if((fp = fopen("test.txt", "r"))!= NULL)
	{
		printf("Succes!\n");
		printf("Opening \"test.txt\" in \"r\" mode !\n");
	}
	else
	{
		printf("Error");
		exit(-1);
	}

	fclose(fp);
	exit(0);

}

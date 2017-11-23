#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE *fp;
	int ch;
	if((fp  = fopen(argv[1], "r"))== NULL)
	{
		printf("File open error\n");
		exit(1);
	}

	ch = fgetc(fp);
	while(!feof(fp))
	{
		fputc(ch, stdout);
		if(ferror(fp))
		{
			printf("Error detected!\n");
			clearerr(fp);
		}
		ch = fgetc(fp);
	}

	fclose(fp);
	exit(0);
}

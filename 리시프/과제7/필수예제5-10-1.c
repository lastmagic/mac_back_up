#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFMAX 1024
int main(void)
{
	char buf[BUFMAX];

	while(fgets(buf, BUFMAX, stdin)!= NULL)
	{
		if(fputs(buf, stdout) == EOF)
		{
			printf("standard output error\n");
			exit(1);
		}
	}
	if(ferror(stdin))
	{
		printf("standard input error\n");
		exit(1);
	}

	exit(0);
}

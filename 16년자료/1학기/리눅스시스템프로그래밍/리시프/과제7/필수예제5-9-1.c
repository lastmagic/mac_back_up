#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c;

	while((c = getc(stdin))!= EOF)
	{
		if(putc(c, stdout) == EOF)
		{
			printf("output error\n");
			exit(1);
		}
	}
	if(ferror(stdin))
	{
		printf("intput error\n");
		exit(1);
	}

	exit(0);
}

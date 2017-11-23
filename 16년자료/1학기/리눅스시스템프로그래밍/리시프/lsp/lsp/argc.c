#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	if(argc == 1)
	{
		fputs("error! you have to enter more than 2 options!\n", stderr);
		exit(1);
	}

	printf("%d option entered!\n\n", argc -1 );
	
	for(int i=0; i<argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	exit(0);
}

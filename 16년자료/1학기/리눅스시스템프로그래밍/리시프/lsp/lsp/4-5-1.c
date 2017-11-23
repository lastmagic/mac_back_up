#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat sbuf;

	if(argc <2)
	{
		printf("usage: a.out file1 file2 ... fileN\n");
		exit(1);
	}

	for(i =1; i<argc; i++)
	{
		if(stat(argv[i], &sbuf)<0)
		{
			printf("%s: stat call error!\n", argv[i]);
			continue;
		}

		sbuf.st_mode |= 0111;
		sbuf.st_mode ^= 0011;

		if(chmod(argv[1], sbuf.st_mode) <0)
		{
			printf("%s: chmod call error!\n", argv[i]);
		}
		else
			printf("%s: file permission was changed.\n", argv[i]);

	}

	exit(0);
}

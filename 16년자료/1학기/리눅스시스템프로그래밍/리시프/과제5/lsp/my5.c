#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "You have to enter more that 1 option\n");
		exit(1);
	}

	int fd;
	if((fd = open(argv[1], O_RDONLY)) < 0)
	{
		fprintf(stderr, "file open error\n");
		exit(1);
	}
	else
	{
		printf("file open successfully!\n");
		printf("File Descriptor: %d\nFile name = %s\n", fd, argv[1]);
	}
}


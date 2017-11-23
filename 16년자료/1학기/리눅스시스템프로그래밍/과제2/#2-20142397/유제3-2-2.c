#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{

	char *fname = "test.txt";
	int fd;
	fd = creat(fname, 0666);
	if(fd > 0)
	{
		printf("Success!\n");
		printf("Filename: %s\nDescriptor : %d\n", fname,fd);
	}
	else
	{
		printf("creat() error\n");
	}
	exit(0);
}

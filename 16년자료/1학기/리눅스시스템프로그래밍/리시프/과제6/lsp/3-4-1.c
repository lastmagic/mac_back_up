#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(void)
{

	char *fname = "test.txt";
	int fd;
	off_t fsize;
	fd = open(fname, O_RDONLY);
	if(fd >0)
	{
		fsize = lseek(fd, 0, SEEK_END);
		printf("The size of <test.txt> is %lld bytes\n",fsize);
	}
	else
	{
		printf("open error\n");
	}

	exit(0);
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(void)
{
	char *fname = "test.txt";
	int fd, rdlen;
	int fd2;
	char buf[BUFSIZE];

	if((fd = open(fname, O_RDONLY, 0644))<0)
	{
		printf("<%s> cannot be opened!\n", fname);
		exit(-1);
	}

	if(dup2(1, 4)==-1)
	{
		fprintf(stderr, "dup2() error\n");
		exit(1);
	}
	
	for(;;)
	{
		rdlen = read(fd, buf, BUFSIZE);
		if(rdlen < 0) break;

		write(4, buf, rdlen);
	}

	exit(0);

}

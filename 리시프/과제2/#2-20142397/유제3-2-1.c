#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){

	char *fname = "test.txt";
	int fd;
	if((fd = creat(fname, 0644))>0)
	{
		close(fd);
		fd = open(fname,O_RDWR);
		printf("Succedd!\n<%s> is new readable and writable\n", fname);
	}
	else
		printf("failed\n");

	exit(0);
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char *fname = "alreay.txt";
	int fd;
	if((fd = open(fname, O_RDWR | O_TRUNC, 0644))<0)
	{
		fprintf(stderr, "file open error\n");
	}
	else
		printf("File open success!\n FD:%d, Fname: %s", fd, fname);

}

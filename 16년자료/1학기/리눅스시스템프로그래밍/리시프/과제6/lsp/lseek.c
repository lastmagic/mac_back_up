#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>


#define MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

char buf1[] = "1234567890";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd;
	
	if((fd = creat("hole", MODE))<0)
	{
		printf("creat error\n");
		exit(1);
	}

	if((write(fd, buf1, 12))!= 12)
	{
		printf("buf1 write error\n");
		exit(1);
	}

	if(lseek(fd, 15000, SEEK_SET) == -1)
	{
		printf("lseek error");
		exit(1);
	}

	if(write(fd, buf2, 12)!= 12)
	{
		printf("buf2 write error\n");
		exit(1);
	}

	return 0;
}

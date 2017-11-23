#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char *fname = "test.txt";
	int fd, newfd;
	int flag;

	if((fd = open(fname, O_RDWR|O_APPEND))<0)
	{
		printf("oepn()");
		exit(-1);
	}
	flag = fcntl(fd,F_GETFL);
	if(flag & O_APPEND)
		printf("fd: O_APPEND flag is set\n");
	else
		printf("fd: O_APPEND flag is NOT set\n");

	flag = fcntl(fd, F_GETFD);
	if(flag & FD_CLOEXEC)
		printf("fd: FD_CLOEXEC flag is set\n");
	else
		printf("fd: FD_CLOEXEC flag is NOT set\n");
	
	fcntl(fd, F_SETFD, FD_CLOEXEC);
	flag = fcntl(fd, F_GETFD);
	if(flag & FD_CLOEXEC)
		printf("fd: FD_CLOEXEC flag is set\n");
	else
		printf("fd: FD_CLOEXEC flag is NOT set\n");


	exit(0);
}

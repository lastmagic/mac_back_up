#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int fd2;
	fd =open("test.txt", O_RDONLY);
	fd2 = fcntl(fd, F_DUPFD);
	printf("fd =%d, fd2= %d\n", fd, fd2);

}

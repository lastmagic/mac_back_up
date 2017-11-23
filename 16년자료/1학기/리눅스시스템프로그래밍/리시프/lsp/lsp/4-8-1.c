#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd;
	int len;
	char buf[20];

	if((fd = open("./tempfile", O_RDWR|O_CREAT|O_TRUNC, 0600))<0)
	{
		printf("first open call error\n");
		exit(1);
	}

	if(unlink("./tempfile")<0)
	{
		printf("unlink call error\n");
		exit(2);
	}

	
	len = write(fd, "How are you?", sizeof(buf));
	lseek(fd, 0, SEEK_SET);
	read(fd, buf, sizeof(buf));
	printf("%s\n", buf);
	close(fd);

	if((fd= open("./tempfile", O_RDWR))<0)
	{
		printf("second open call error\n");
		exit(5);
	}
	else
		close(fd);

	exit(0);
	
}

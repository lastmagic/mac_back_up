#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	char buf[20];

	if(argc != 3)
	{
		printf("usage: a.out oldname newname\n");
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY))<0)
	{
		printf("first open call error\n");
		exit(2);
	}
	else
		close(fd);
	
	if((rename(argv[1], argv[2]))<0)
	{
		printf("rename call error!\n");
		exit(3);
	}

	if((open(argv[1], O_RDONLY))<0)
	{
		printf("second open call error\n");
	}
	else
	{
		printf("It's very strange!\n");
		exit(5);
	}
	
	if((open(argv[2], O_RDONLY))<0)
	{
		printf("third open call error\n");
		exit(5);
	}

	printf("Everything is good\n");
	exit(0);
	

}

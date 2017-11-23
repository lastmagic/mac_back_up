#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	struct stat sbuf;

	if((fd = open("myfile", O_RDWR|O_CREAT, 0600))<0)
	{
		printf("open call error!\n");
		exit(1);
	}

	close(fd);
	
	stat("myfile", &sbuf);
	printf("# 1st stat call # UID: %d   	GID:%d\n", sbuf.st_uid, sbuf.st_gid);
	
	if((chown("myfile", 501, 100))<0)
	{
		printf("chown call error\n");
		exit(2);
	}

	stat("myfile", &sbuf);
	printf("# 2nd stat call # UID:%d		GID:%d\n", sbuf.st_uid, sbuf.st_gid);

	if(unlink("myfile")<0)
	{
		printf("You cannot remove <myfile>\n");
		exit(3);
	}

	exit(0);
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void)
{
	if(open("zoo", O_RDWR)<0)
	{
		printf("file open error\n");
		exit(1);
	}

	if(unlink("zoo")<0)
	{
		printf("file unlink error\n");
		exit(1);
	}

	printf("file unlinked\n");
	sleep(10);
	printf("done\n");
	exit(0);
}

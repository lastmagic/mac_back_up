#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char c;
	if((fd = open("test.txt", O_RDONLY))<0)
	{
		printf("<test.txt> cannot be opened!\n");
		exit(1);
	}

	for(;;)
	{
		if(read(fd, &c, sizeof(c))<=0)
			break;
		putchar(c);
	}
	
	exit(0);
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char *fname = "Heedong.txt";
	int fd;
	fd = open(fname, O_RDONLY);
	if(fd > 0)
	{
		printf("File open Successfully!\n");
		printf("File name : %s\nFile Descriptor: %d\n", fname, fd);
		exit(0);
		
	}

	else
	{
		printf("File open error! Please Check your file!\n");
		exit(1);
	}
}


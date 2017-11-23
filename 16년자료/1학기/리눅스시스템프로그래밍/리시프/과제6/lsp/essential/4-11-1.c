#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>

int main(int argc, char *argv[])
{
	int i, fd;
	struct stat stat_buf;
	struct utimbuf time_buf;

	for(i = 1; i<argc; i++)
	{
		if(stat(argv[i], &stat_buf)<0)
		{
			printf("stat error[%s]\n", argv[i]);
			continue;
		}
		if((fd = open(argv[i], O_RDWR | O_TRUNC))<0)
		{
			printf("open error[%s]\n", argv[i]);
			continue;
		}

		close(fd);

		time_buf.actime = stat_buf.st_atime;
		time_buf.modtime = stat_buf.st_mtime;
		if(utime(argv[i], &time_buf)<0)
		{
			printf("utime error[%s]\n", argv[i]);
			continue;
		}

	}
		exit(0);
		
}

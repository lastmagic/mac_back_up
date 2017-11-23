#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char * argv[])
{
	struct stat stat_buf;

	if(stat("zoo", &stat_buf)<0)
		printf("stat error[zoo]\n");
	if(chmod("zoo", (stat_buf.st_mode & ~S_IXGRP)|S_ISUID)<0)
		printf("chmod error[zoo]\n");
	if(chmod("bee", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | S_IXOTH)<0)
		printf("chmod error[bee]\n");

	exit(0);
}

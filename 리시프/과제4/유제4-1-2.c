#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat statbuf;
	int ret;

	if(argc <2)
	{
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		exit(1);
	}
	ret = stat(argv[1], &statbuf);
	if(ret)
	{
		fprintf(stderr, "stat() error\n");
		exit(1);
	}
	printf("%s is %lld bytes\n", argv[1], statbuf.st_size);
	exit(0);
}

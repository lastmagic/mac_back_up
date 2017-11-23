#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("usage: a.out oldname newname\n");
		exit(1);
	}

	if(link(argv[1], argv[2]) <0)
	{
		printf("link error!\n");
		exit(2);
	}
	else
		printf("step1 passed.\n");

	if(remove(argv[1])<0)
	{
		printf("unlink error!\n");
		remove(argv[2]);
		exit(3);
	}
	else
		printf("step2 passed.\n");

	printf("success!\n");
	exit(0);

}

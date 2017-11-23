#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PATH_MAX 1024

int main(void)
{
	char *path;
	if(chdir("./test")<0)
	{
		printf("chdir failed\n");
		exit(1);
	}

	path = malloc(PATH_MAX);
	if(getcwd(path, PATH_MAX) == NULL)
	{
		printf("getcwd failed\n");
		exit(1);
	}

	printf("current directory = %s\n", path);
	exit(0);
}

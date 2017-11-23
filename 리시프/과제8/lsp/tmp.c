#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 4096

int main(void)
{
	char name[L_tmpnam], line[MAX_LINE];
	FILE *fp;

	printf("%s\n", tmpnam(NULL));

	tmpnam(name);
	printf("%s\n", name);

	if((fp = tmpfile())== NULL)
	{
		printf("tmpfile failed\n");
		exit(1);
	}

	fputs("tmpfile create temporary file.\n", fp);
	rewind(fp);

	if((fgets(line, sizeof(line), fp))== NULL)
	{
		printf("fgets failed\n");
		exit(1);
	}

	fputs(line, stdout);
	exit(0);
}

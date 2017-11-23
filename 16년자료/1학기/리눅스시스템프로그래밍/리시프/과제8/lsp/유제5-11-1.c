#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char *argv[])
{
	FILE *fp;
	char buf[256];
	if((fp = fopen(argv[1], "w+")) == NULL)
	{
		printf("fopen error\n");
		exit(1);
	}

	fputs("Input String >> ", stdout);

	gets(buf);
	puts(buf);

	rewind(fp);

	fgets(buf, sizeof(buf), fp);
	fputs(buf, fp);

	fclose(fp);
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *tmpfp;
	char tmpname[L_tmpnam];
	char buf[256];

	printf("Temporary filename <<%s>>\n", tmpnam(tmpname));
	if((tmpfp = tmpfile())== NULL)
	{
		printf("timpfile create error\n");
		exit(1);
	}
	fputs("create tmpfile success\n", tmpfp);
	rewind(tmpfp);

	fgets(buf, sizeof(buf), tmpfp);
	puts(buf);

	exit(0);
}

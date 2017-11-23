#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_setbuf(FILE *fp, char *buf);

int main(void)
{
	char buf[BUFSIZ];
	FILE *fp;

	fp = fopen("/dev/ttys000", "w");

	my_setbuf(fp, buf);
	
	fprintf(fp, "Hello,"); sleep(1);
	fprintf(fp, "UNIX!"); sleep(1);
	fprintf(fp, "\n"); sleep(1);

	my_setbuf(fp, NULL);
	fprintf(fp, "How "); sleep(1);
	fprintf(fp, "are "); sleep(1);
	fprintf(fp, "you?"); sleep(1);
	fprintf(fp, "\n"); sleep(1);

	exit(0);
}


void my_setbuf(FILE *fp, char *buf)
{
	int mode, fd;
	size_t size;
	
	size = BUFSIZ;
	fd = fileno(fp);

	if(buf == NULL)
		;
	else if(isatty(fd))
	{
		mode = _IOLBF;
		setvbuf(fp, buf, mode, size);
	}
	else
	{
		mode = _IOFBF;
		setvbuf(fp, buf, mode, size);
	}
	
}

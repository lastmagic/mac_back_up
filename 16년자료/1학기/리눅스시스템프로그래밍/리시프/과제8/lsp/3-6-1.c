#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define PMODE 0644
#define BUFSIZ 512

int main(int argc, char *argv[])
{
	int fdin, fdout, n;
	char buf[BUFSIZ];

	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s filein fileout\n", argv[0]);
		exit(1);
	}

	if((fdin = open("password", O_WRONLY|O_CREAT|O_TRUNC, PMODE))==-1)
	{
		printf("%s\n", argv[1]);
		exit(2);
	}

	if((fdout = open("password", O_RDONLY))==-1)
	{
		printf("%s\n", argv[2]);
		exit(3);
	}

	while((n = read(fdin, buf, BUFSIZ))>0)
	{
		write(fdout, buf, BUFSIZ);
	}

	exit(0);

}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char *fname = "test.txt";
	int fd1, fd2, cnt;
	char buf[20];

	fd1 = open(fname, O_RDONLY|O_CREAT, 0644);
	fd2 = open(fname, O_RDONLY|O_CREAT, 0644);

	if((fd1<0)||(fd2<0))
	{
		printf("<%s> cannot be opened!", fname);
		exit(-1);
	}

	cnt =read(fd1, buf, 12);
	buf[cnt] = 0;
	printf("fd1's first printf: %s\n", buf);
	lseek(fd1, 1, SEEK_CUR);
	cnt = read(fd1, buf, sizeof(buf));
	buf[cnt] = 0;
	printf("fd2's second printf: %s\n", buf);

	cnt = read(fd2, buf ,12);
	buf[cnt] = 0;
	printf("fd2's first printf: %s\n", buf);
	lseek(fd2, 1, SEEK_CUR);
	cnt = read(fd2, buf, sizeof(buf));
	buf[cnt] = 0;
	printf("fd2's second printf: %s\n", buf);

	exit(0);
}


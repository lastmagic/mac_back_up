#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 40

int main(void)
{
	char buf[BUFSIZE];
	int n;

	n = read(0, buf, BUFSIZE);
	write(1,buf, n);
	exit(0);
}

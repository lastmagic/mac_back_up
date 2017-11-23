#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a,b,i;
	char ubuf[BUFSIZ];

	setbuf(stdin, ubuf);
	scanf("%d %d", &a, &b);
	for(i = 0; i<BUFSIZ; i++)
	{
		if(ubuf[i] == '\n')
			break;
		putchar(ubuf[i]);
	}

	putchar('\n');

	exit(0);
}

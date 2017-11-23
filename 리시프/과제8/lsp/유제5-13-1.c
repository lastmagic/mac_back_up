#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *fname = "test.txt";
	long position;
	int ch;
	FILE *fp;
	
	if((fp = fopen(fname, "r")) == NULL)
	{
		printf("File open error\n");
		exit(1);
	}

	printf("Input number>>");
	scanf("%ld", &position);
	fseek(fp, position-1, SEEK_SET);
	ch = getc(fp);
	printf("%ldth character => %c\n", position, ch);

	exit(0);
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c, number = 0;
	char op;
	FILE *fp;

	if((fp = fopen("test.txt", "r"))== NULL)
	{
		printf("File open error!\n");
		exit(1);
	}

	while(!feof(fp))
	{
		while((c = fgetc(fp))!= EOF && isdigit(c))
			number = 10 * number + c - 48;
		fprintf(stdout, "%d\n", number);
		number = 0;

		if(c != EOF)
		{
			ungetc(c, fp);
			op  = fgetc(fp);
			printf("Operator=>%c\n", op);
		}

	}
	fclose(fp);
	exit(0);

}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct test
{
	int No;
	char name[80];
};

int main(void)
{
	struct test t, t1;
	FILE *fp;

	if((fp = fopen("test.dat", "w")) ==NULL)
	{
		printf("File open error\n");
		exit(1);
	}

	printf("Input No>>");
	scanf("%d", &t.No);
	printf("Input name>>");
	scanf("%s", t.name);

	if((fwrite(&t, sizeof(struct test), 1, fp))!= 1)
	{
		printf("fwrite error\n");
		exit(1);
	}

	fclose(fp);

	if((fp = fopen("test.dat", "r"))== NULL)
	{
		printf("File open error\n");
		exit(1);
	}


	if((fread(&t1, sizeof(t1), 1, fp))!=1)
	{
		printf("fred error\n");
		exit(1);
	}

	printf("\nNo name \n");
	printf("================\n");
	printf("%d		%s\n", t1.No, t1.name);

	fclose(fp);

	exit(0);

}


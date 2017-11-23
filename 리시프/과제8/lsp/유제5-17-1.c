#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	int age;
	char name[20];
	
	fp = fopen("test.dat", "r");
	fscanf(fp, "%s %d",name, &age);
	fclose(fp);

	fp = fopen("test.txt", "w");
	fprintf(fp, "%s is %d years old", name, age);
	fclose(fp);

	exit(0);
	
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *str ="200\n";
	char *temp;
	int num;
	temp = strtok(str, "\n");
	num = atoi(temp);

	printf("num = %s", str);
}

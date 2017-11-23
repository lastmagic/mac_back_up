#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *str="ls";
	char *temp[2];
	temp[1] = str;

	printf("%s", temp[1]);
}


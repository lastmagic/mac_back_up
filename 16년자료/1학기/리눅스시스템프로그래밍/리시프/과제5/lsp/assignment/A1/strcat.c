#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *str[3];
	char *tmp="+a";
	str[0] = "+b";
	str[1] ="+c";
	str[2] ="+d";
	char *option[3];
	char arg[100]="Test";
	int i=0;
	for(i=0; i<3;i++)
	{
		strcat(arg, str[i]);
	}
	printf("%s\n", arg);
}


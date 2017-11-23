#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char *str ="-lcm";
	char *temp;


	temp = strchr(str, 'a');
	printf("%s\n", temp);
}

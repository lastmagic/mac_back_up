#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str[100];
	fgets(str, sizeof(str), stdin);
	printf("%s", str);
}

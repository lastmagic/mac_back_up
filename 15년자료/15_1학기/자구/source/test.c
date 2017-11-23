#include <stdio.h>


int puls(int a, int b)
{
	return a + b;
}

int main(void)
{
	int a = 3, b = 5, c;

	c = puls(a, b);

	printf("%d", c);

	return 0;
}


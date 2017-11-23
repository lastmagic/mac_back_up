#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	if(lseek(STDIN_FILENO, 0, SEEK_SET)==-1)
	{
		printf("lseek error\n");
	}
	else
		printf("lseek OK!\n");

	return 0;
}

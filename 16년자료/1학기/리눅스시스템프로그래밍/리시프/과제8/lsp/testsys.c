#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char *coname;
	char *cmp;
	while(1)
	{
		printf("20142397 ");
		scanf("%s", coname);
		if(strcmp(coname, "ls") == 0)
			system("ls");
		system("clear");
	}
	
	exit(0);
}

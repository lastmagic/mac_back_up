#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define TABLESIZ (sizeof(table)/sizeof(*table))

int main(int argc, char * argv[])
{
	int i;
	struct
	{
		int mode;
		char *text;
	}table[] = {
		{0, "exists"},
		{1, "execute"},
		{2, "write"},
		{4, "read"}
	};

	for(i =0 ;i<TABLESIZ; i++)
	{
		if(access(argv[1], table[i].mode)==0)
			printf("%s -ok\n", table[i].text);
		else
			printf("%s\n", table[i].text);
	}

	exit(0);

}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buf[] = "abcdefgh";
	char *str[10];
	int i, tok_count=0;
	str[tok_count] = strtok(buf, "bde");
	for(i=0; i<10; i++)
	{
		if(str[tok_count]== NULL)
			break;
		tok_count++;
		printf("token %d: %s\n", tok_count, str[tok_count]);
		str[tok_count] = strtok(NULL, "bde");
	}
	for(i =0; i< 9 ;i++)
	{
		printf("buf[%d] = %d %c\n", i, buf[i], buf[i]);
	}
	return 0;
}


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *in, *out;
	struct pirate
	{
		char name[100];
		unsigned long booty;
		unsigned int beard_len;
	}p, blackbeard = {"Edward Teach", 950, 48};

	out = fopen("data", "w");
	if(!out)
	{
		printf("fopen");
		exit(1);
	}
	if((fwrite(&blackbeard, sizeof(struct pirate), 1, out))!=1)
	{
		printf("fwrite\n");
		exit(1);
	}

	if(fclose(out))
	{
		printf("fclose\n");
		exit(1);
	}

	in  = fopen("data", "r");
	if(!in)
	{
		printf("fopen\n");
		exit(1);
	}

	if((fread(&p, sizeof(struct pirate), 1, in))!=1)
	{
		printf("fread\n");
		exit(1);
	}

	if(fclose(in))
	{
		printf("fclose\n");
		exit(1);
	}

	printf("name=\"%s\" booty = %ld beard_len=%u\n",p.name, p.booty, p.beard_len);
	exit(0);
	
}


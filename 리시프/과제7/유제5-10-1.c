#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *prompt = "Prompt>>";
	char command[80];

	while(1)
	{
		fputs(prompt, stdout);
		if(fgets(command, sizeof(command), stdin)!=NULL)
		{
			system(command);
		}
		if(feof(stdin)==1||ferror(stdin)==1)
			break;
	}

	fprintf(stdout, "Good bye...\n");
	fflush(stdout);

	exit(0);
}

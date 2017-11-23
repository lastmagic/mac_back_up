#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

pr_sysconf(char *mesg, int name)
{
	long val;
	errno = 0;
	fputs(mesg, stdout);
	if((val = sysconf(name)) < 0)
	{
		if(errno != 0)
		{
			fprintf(stderr, "sysconf error\n");
			exit(1);
		}
		fputs("((not defined)\n", stdout);
	}
	else
		printf("%ld\n", val);
}

pr_pathconf(char *mesg, char *path, int name)
{
	long val;
	errno = 0;
	fputs(mesg, stdout);
	if((val = pathconf(path, name)) < 0)
	{
		if(errno != 0)
		{
			fprintf(stderr, "pathconf error, path = %s\n", path);
			exit(1);
		}
		fputs("(no limit)\n", stdout);
	}
	else
		printf("%ld\n", val);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: ./a.out <dirname>\n");
		exit(1);
	}

	
}

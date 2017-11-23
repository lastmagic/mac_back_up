#include <unistd.h>
#include <stdioh.>
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
		fputs("(not defined)\n", stdout);
	}
	else
		printf("%ld\n", val);
}

pr_pathconf(char *mesg, char *path, int name)
{
	long val;
	errno = 0;
}

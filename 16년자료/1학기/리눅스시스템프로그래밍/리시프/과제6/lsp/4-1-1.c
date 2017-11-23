#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

struct stat sbuf;

void checkfile(char *, time_t*);

void main(int argc, char *argv[])
{
	int i;
	time_t sav_time;

	if(argc != 2)
	{
		printf("usage: checkmod filename\n");
		exit(1);
	}

	if(stat(argv[1], &sbuf)<0)
	{
		printf("stat call error\n");
		exit(2);
	}

	sav_time = sbuf.st_mtime;
	for(;;)
	{
		checkfile(argv[1], &sav_time);
		sleep(1);
	}

}

void checkfile(char *fname, time_t *time)
{
	if(stat(fname, &sbuf)<0)
	{
		printf("Warning: checkfile() error\n");
		exit(3);
	}
	else
		if(sbuf.st_mtime != *time)
		{
			printf("Warning: %s was modified!\n", fname);
			*time = sbuf.st_mtime;
		}
}

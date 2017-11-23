#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <dirent.h>

#ifdef PATH_MAX
static int pathmax = PATH_MAX;
#else
static int pathmax = 0;
#endif
#define MAX_PATH_GUSSED 1024 //최대경로 이름의 크기에 대한 어림값

#ifdef LINE_MAX
#define LINE_MAX 2048
#endif

char *pathname;
char grep_cmd[LINE_MAX], command[LINE_MAX];

int do_grep(void)
{
	struct stat statbuf;
	struct dirent *dirp;
	DIR *dp;
	char *ptr;

	if(lstat(pathname, &statbuf)<0)
	{
		fprintf(stderr, "stat error for %s\n", pathname);
		return -1;
	}

	if((S_ISDIR(statbuf.st_mode))==0)
	{
		sprintf(command, "%s %s", grep_cmd, pathname);
		printf("%s : \n", pathname);
		system(command);
		return 0;
	}

	ptr = pathname + strlen(pathname);
	*ptr++ = '/'; *ptr = '\0';
	if((dp = opendir(pathname)) == NULL)
	{
		fprintf(stderr, "can't open directory<%s>", pathname);
		return 0;
	}
	while((dirp = readdir(dp)) != NULL)
	{
		if(strcmp(dirp->d_name, ".")&&strcmp(dirp->d_name,".."))
		{
			strcpy(ptr, dirp->d_name);
			if(do_grep()<0)
				break;
		}
	}

	ptr[-1] = 0;
	closedir(dp);
	return 0;


}

int mk_grep(int  argc, char *argv[])
{
	int i;
	strcpy(grep_cmd, " grep");
	for(i = 1; i< argc-1; i++)
	{
		strcat(grep_cmd, " ");
		strcat(grep_cmd, argv[i]);
	}

	return 0;
}

int main(int argc, char *argv[])
{
	if(argc <2)
	{
		printf("usage: a.out [-CVbcilnsvwx] [-num] [-A num] [-B num] [-f file]\n[-e] expr [directory]\n");
		exit(1);
	}

	if(pathmax == 0)
	{
		if((pathmax = pathconf("/", _PC_PATH_MAX))<0)
			pathmax = MAX_PATH_GUSSED;
		else
			pathmax++;
	}

	if((pathname = (char *)malloc(pathmax+1))==NULL)
	{
		fprintf(stderr, "malloc error\n");
		exit(2);
	}

	strcpy(pathname, argv[argc-1]);

	mk_grep(argc, argv);
	do_grep();
	exit(0);
}

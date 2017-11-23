#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>

#define DIRSIZE MAXNAMLEN

int main(int argc, char *argv[])
{
	DIR *dirp;
	struct dirent *dentry;
	char filename[DIRSIZE+1];
	struct stat stbuf;

	if((dirp = opendir(argv[1]))==NULL || chdir(argv[1]) == -1)
	{
		printf("%s\n", argv[1]);
		exit(1);
	}

	while((dentry = readdir(dirp))!=NULL)
	{
		if(dentry->d_ino == 0)
			continue;
		memcpy(filename, dentry->d_name, DIRSIZE);
		if(stat(filename, &stbuf) == -1)
		{
			printf("%s\n", filename);
			break;
		}

		if((stbuf.st_mode&S_IFMT) == S_IFREG)
			printf("%-14s %lld\n", filename, stbuf.st_size);
		else
			printf("%-14s\n", filename);

	}

	exit(0);
}

#include <sys/stat.h>

int stat(const char*restrict pathname, struct stat *restrict buf);
int lstat(const char *restrict pathname, struct stat *restrict buf);
int fstat(int filedes, struct stat *buf);
// s = 0 e > -1

#include <unistd.h>

int access(const char *pathname, int mode);
// s=0 e > -1


#include <sys/stat.h>

int stat(const char*restrict pathname, struct stat *restrict buf);
int lstat(const char *restrict pathname, struct stat *restrict buf);
int fstat(int filedes, struct stat *buf);

// s > 0 e > -1

#include <unistd.h>

int access(const char *pathname, int mode);
// s > 0 e> -1

#include <sys/stat.h>

int stat(const char *restrict pathname, struct stat *restrict buf);
int lstat(const char *restrict pathname, strcut stat *restrict buf);
int fstat(int filedes, struct stat *buf);


#include <unistd.h>

int access(const char *pathname, int mode);


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int i;
	char *str;
	struct stat file_info;

	for(i =1 ; i< argc; i++)
	{	
		printf("name = %s, type = ", argv[i]);
		if(lstat(argv[i], &file_info)<0)
		{
			printf("lstat error\n");
			continue;
		}
		if(S_ISREG(file_info.st_mode))
			str ="regular";
		else if(S_ISDIR(file_info.st_mode))
			str ="directory";
		else if(S_ISCHR(file_info.st_mode))
			str ="charater";
		else if(S_ISBLK(file_info.st_mode))
			str ="blank";
		else if(S_ISFIFO(file_info.st_mode))
			str ="fifo";
		else if(S_ISLNK(file_info.st_mode))
			str ="symbolic link";
		else if(S_ISSOCK(file_info.st_mode))
			str ="socket";
		else
			str = "unknown mode";

		printf("%s\n", str);
	}

	
}

#include <unistd.h>

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("usage: a.out pathname\n");
		exit(1);
	}
	if(access(argv[1], R_OK)<0)
		printf("access error for %s\n", argv[1]);
	else
		printf("read access OK\n");
	if(open(argv[1], O_RDONLY)<0)
		printf("open error for %s\n", argv[1]);
	else
		printf("open for reading ok\n");
	exit(0);
}

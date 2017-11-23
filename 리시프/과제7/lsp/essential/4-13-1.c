#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>

#ifdef PATH_MAX
#define	PATH_MAX 1024
#endif

static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;
typedef int function(const char *, const struct stat*, int);

static function myfunc;
static int myftw(char *, function *);
static int dopath(function *);

int main(int argc, char *argv[])
{
	int ret;
	if(argc != 2)
	{
		printf("usage: a.out starting-path\n");
		exit(1);
	}

	ret = myftw(argv[1], myfunc);
	ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;
	if(ntot == 0)
		ntot = 1;
	printf("regualr files = %4ld, %2.2f %%\n", nreg, nreg*100.0/ntot);
	printf("directories  = %4ld, %2.2f %%\n", ndir, ndir*100.0/ntot);
	printf("block special = %4ld, %2.2f %%\n", nblk, nblk*100.0/ntot);
	printf("char special = %4ld, %2.2f %%\n", nchr, nchr*100.0/ntot);
	printf("symbolic links = %4ld, %2.2f %%\n", nslink, nslink*100.0/ntot);
	printf("sockets  = %4ld, %2.2f %%\n", nsock, nsock*100.0/ntot);


	exit(ret);

}

#define FTW_F 1
#define FTW_D 2
#define FTW_DNR 3
#define FTW_NS 4

static char *fullpath;
static int myftw(char *path, function *func)
{
	fullpath = malloc(PATH_MAX + 1);

	strncpy(fullpath, path, PATH_MAX);
	fullpath[PATH_MAX-1] = 0;
	return(dopath(func));
}

static int dopath(function *func)
{

	struct stat statbuf;
	struct dirent *dirp;
	DIR *dp;
	int ret;
	char *ptr;

	if(lstat(fullpath, &statbuf)<0)
		return(func(fullpath, &statbuf, FTW_NS));
	if(S_ISDIR(statbuf.st_mode) == 0)
		return(func(fullpath, &statbuf, FTW_F));

	if((ret = func(fullpath, &statbuf, FTW_D))!= 0)
		return(ret);

	ptr = fullpath + strlen(fullpath);
	*ptr++ = '/';
	*ptr = 0;

	if((dp = opendir(fullpath))== NULL)
		return(func(fullpath, &statbuf, FTW_DNR));

	while((dirp = readdir(dp))!=NULL)
	{
		if(strcmp(dirp->d_name, ".")==0||strcmp(dirp->d_name, "..")==0)
			continue;

		strcpy(ptr, dirp->d_name);

		if((ret = dopath(func))!=0)
			break;

	}

	ptr[-1] = 0;

	if(closedir(dp)<0)
	{
		printf("can't close directory [%s]\n", fullpath);
		exit(0);
	}

	return(ret);

}

static int myfunc(const char *path, const struct stat *stat_ptr, int type)
{

	switch(type)
	{
		case FTW_F:
			switch(stat_ptr->st_mode & S_IFMT)
			{
				case S_IFREG: nreg++; break;
				case S_IFBLK: nblk++; break;
				case S_IFCHR: nchr++; break;
				case S_IFIFO: nfifo++; break;
				case S_IFLNK: nslink++; break;
				case S_IFSOCK: nsock++; break;
				case S_IFDIR:
							   printf("for S_IFDIR for[%s]\n", path);
							   exit(1);

			}

			break;

		case FTW_D:
			ndir++;
			break;
		case FTW_DNR:
			printf("can't read directory [%s]\n", path);	
			break;

		case FTW_NS:
			printf("stat error [%s]\n", path);
			break;

		default:
			printf("unknown type %d for path [%s]\n", type, path);
			exit(1);
	}

	return(0);
}

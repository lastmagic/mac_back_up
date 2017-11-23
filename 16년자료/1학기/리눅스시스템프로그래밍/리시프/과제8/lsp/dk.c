#include <sys/stat.h>

int stat(pathname, buf);
int lstat(pathname, buf);
int fstat(int fildes, struct stat *buf);

s > 0 e > -1;

#include <unistd.h>

int access(const char *pathname , int mode);

s > 0 e> -1;

S_ISREG;
S_ISDIR;
S_ISCHR;



if(lstat(argv[1], &file_info)<0)
{

}
if(access(argv[1], R_OK)<0)

;
if(open(argv[1], O_RDONLY)<0)
{
	
}

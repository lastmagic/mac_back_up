#include <fcntl.h>

int open(const char *pathname, int oflag, mode_t mode);
int creat(const char *pathname, mode_t mode);
==open(pathname, O_RDWR|O_CREAT|O_TRUNC, mode);

#include <unistd.h>

int close(int filedes); //성공시 0 실패시 -1 return to system.
off_t lseek(int filedes, off_t offset, int whence);
//success > new file offset, fail >  -1

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	if(lseek(STDIN_FILENO, 0, SEEK_END) == -1)
		printf("lseek error\n");
	else
		printf("lseek ok!\n");

	exit(0);
}

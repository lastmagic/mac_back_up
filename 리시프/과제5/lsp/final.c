#include <fcntl.h>

int open(const char *pathname, int oflag ,mode_t mode);
int creat(const char *pathname, mode_t mode);

#include <unistd.h>

int close(int filedes);
off_t lseek(int filedes, off_t offset, int whence);

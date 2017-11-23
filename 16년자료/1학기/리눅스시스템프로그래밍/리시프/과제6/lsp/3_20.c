#include <unistd.h>

ssize_t read(int filedes, void *buf, size_t nbytes);
//return read bytes, end of file 0 
ssize_t write(int filedes, void *buf, size_t nbytes);
//return write bytes

ssize_t pread(int filedes, void *buf, size_t nbytes, off_t offset);
ssize_t pwrite(int filedes, void *buf, size_t nbytes, off_t offset);

#include <unistd.h>

int dup(int filedes);
//return new filedes, e > -1
int dup2(int filedes, int filedes2);
//return new filedes== filedes2, e> -1


#include <unistd.h>

void sync(void);

int fsycn(int filedes);
int fdatasync(int filedes);

// s > 0 e >-1


#include <fcntl.h>
int fcntl(int filedes, int cmd, .../*int arg*/...);
//return s > depends on cmd, e > -1`

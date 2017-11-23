#include <unistd.h>

ssize_t read(int filedes, void *buf, size_t nbytes);

ssize_t write(int filedes, void *buf, size_t nbytes);


#include <unistd.h>

ssize_t pread(int filedes, void *buf, size_t nbytes, off_t offset);

ssize_t pwrite(int filedes, void *buf, size_t nbytes, off_t offset);

int dup(int filedes);
int dup2(int filedes, int filedes2);

void sync(void);
int fsync(int filedes);
int fdatasync(int filedes);

//s > 0 e > -1

#include <fcntl.h>

int fcntl(int filedes, int cmd, .../* int arg */...);
//s > depends on cmd, e > -1

F_DUPFD;
F_GETFD;
F_SETFD;
F_GETFL;
F_SETFL;
F_GETTOWN;
F_SETTOWN;



#include <unistd.h>

ssize_t read(int filedes, void *buf, size_t nbytes);
ssize_t write(int filedes, void *buf, size_t nbytes);

ssize_t pread(int filedes, void *buf, size_t nbytes, off_t offset);
ssize_t pwrite(int filedes, void *buf, size_t nbytes, off_t offset);
// s> read, write bytes, end of file >0, e >- 1

int dup(int filedes);
int dup2(int filedes, int filedes2);
//s > filedes, e> -1
void sync(void);
int fsync(int filedes);
int fdatasync(int filedes);
// s> 0 e> -1

#include <fcntl.h>

int fcntl(int filedes, int cmd, .../*int arg*/...);
// s > depends on cmd, e > -1

F_DUPFD;
F_GETFD;
F_SETFD;
F_GETFL;
F_SETFL;
F_GETOWN;
F_SETOWN;

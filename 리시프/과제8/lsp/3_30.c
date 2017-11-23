#include <utime.h>

int utime(const char *pathname, const struct utimebuf *times);
// s> 0 e> -1

struct utimebuf
{
	time_t actime;
	time_t modtime;
}

#include <sys/stat.h>

int mkdir(const char*pathname, mode_t mode);
int rmdir(const char*pathname);
// s>0 ,e>-1

#include <dirent.h>

DIR *opendir(const char*pathname);
//s> pointer, e>NULL

struct dirent *readdir(DIR *dp);
// s> pointer, end of dir || e > NULL

void rewinddir(DIR *dp);

int closedir(DIR *dp);
// s> 0, e> -1

long telldir(DIR *dp);
// dp에 해당하는 디렉토리 안의 현재위치

void seekdir(DIR *dp, long loc);


#include <unistd.h>

int chdir(const char *pathname);
int fchdir(int filedes);
// s> 0, e> -1

char *getcwd(char *buf, size_t size);
char *get_current_dir_name(void);
// s> buf, e> NULL



#include <utime.h>

int utime(const char *pathname, const struct utimebuf *times);
// s>0 e>-1

#include <sys/stat.h>

int mkdir(const char *pathname, mode_t mode);
int rmdir(const char *pathanme);
// s>0, e>-1


#include <unistd.h>

int chdir(const char*pathname);
int fchdir(int filedes);
// s>0, e>-1

char *getcwd(char *buf, size_t size);
char *get_cureent_dri_name(void);
// s>buf, e>NULL;



#include <utime.h>
int utime(const char*pathname, struct utimebuf *times);
//s>0 e>-1

#include <sys/stat.h>
int mkdir(const char*pathname, mode_t mode);
int rmdir(const char*pathname);

#include <unistd.h>
int chdir(const char*pathname);
int fchdir(int filedes);
// s>0, e>-1

char *getcwd(char *buf, size_t size);
char *get_cureent_dir_name(void);
// s>buf, e>NULL

#include <dirent.h>

DIR *opendir(const char*pathname);
// s> pointer, e>NULL;

struct dirent *readdir(DIR *dp);
// s> pointer, end of file or e > NULL.

void rewinddir(DIR *dp);

int closedir(DIR *dp);
//s> 0, e>-1

void seekdir(DIR *dp, long loc);








#include <dirent.h>

DIR *opendir(const char *pathname);
// s>pointer, e>NULL

struct dirent *readdir(DIR *dp);
// s>pointer, end of file or e > NULL

void rewinddir(DIR *dp);

int closedir(DIR *dp);
// s>0, e>-1
long telldir(DIR *dp);
//dp 에 해당하는 디렉토리 안의 현재위치
void seekdir(DIR *dp, long loc);


#include <utime.h>
int utime(const char*pathname. const struct utimebuf *times);
//s>0, e>-1

#include <sys/stat.h>
int mkdir(const char*pathname, mode_t mode);
int rmdir(const char*pathname);
//>S>0 E>-1
#include <unistd.h>

int chdir(const char*pathname);
int fchdir(int filedes);
// S>0 E>-1
char *getcwd(char *buf, size_t size);
char *get_current_dir_name(void);
//s> buf, e> NULL



#include <dirent.h>

DIR *opendir(const char*pathname);
// s > pointer ,e> NULL
struct dirent *readdir(DIR *dp);
// S> POINTER, END OF dir, E > NULL
void rewinddir(DIR *dp);

int closedir(DIR *dp);
// s> 0, e>-1
void seekdir(DIR *dp, long loc);

long telldir(DIR *dp);
//s>dp에 해당하는 디렉토리 안의 현재위치


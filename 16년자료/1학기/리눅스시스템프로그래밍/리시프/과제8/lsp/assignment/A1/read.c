#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int len;
	char buf3[10]="asdfasdfas";
	char buf4[100]="12345678901234567890";
	fd = open("store.txt", O_CREAT|O_RDWR|O_TRUNC, 0644);
	len = write(fd, buf4, sizeof(buf4));
	lseek(fd, 0 ,SEEK_SET);
	len = write(fd, buf3, sizeof(buf3));
	printf("sizeof(buf3) = %lu\n", sizeof(buf3));
	printf("sizeof(buf4) = %lu\n", sizeof(buf4));
/*	printf("len = %d\n", len);
	lseek(fd, 0, SEEK_SET);
	len = write(fd, buf2, sizeof(buf2));
	printf("len = %d\n", len);
	len = read(fd, buf1, sizeof(buf1));
	printf("len = %d\n", len);
	printf("buf1 = %s\n", buf1);
*/	
}

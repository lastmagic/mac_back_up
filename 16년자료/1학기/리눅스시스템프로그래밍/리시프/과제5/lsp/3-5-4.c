#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEBUG 1
#define TABSIZE 100
#define BUFSIZE 512

int main(int argc, char *argv[])
{
	int n, i, entry, len;
	int fd;
	long offset;
	static struct
	{
		long offset;
		int len;
	} table[TABSIZE];
	char buf[BUFSIZE];

	if((fd = open(argv[1], O_RDONLY))==-1)
	{
		printf("%s\n", argv[1]);
		exit(1);
	}

	entry = 0;
	offset = 0;
	while((n = read(fd, buf, sizeof(buf))) > 0)
	{
		for(i = 0; i < n; i++)
		{
			table[entry].len++;
			offset++;
			if(buf[i] == '\n')
				table[++entry].offset = offset;
		}
	}
#ifdef DEBUG
	for(i = 0; i< entry; i++)
		printf("%d : %ld, %d\n", i+1, table[i].offset, table[i].len);
#endif
	for(;;)
	{
		printf("Enter line number: ");
		scanf("%d", &n);

		if(--n < 0)
			break;

		lseek(fd, (long)table[n].offset, 0);
		if(read(fd, buf, table[n].len * sizeof(char))==0)
				continue;

		buf[table[n].len] = '\0';
		printf("%s", buf);
	}

	close(fd);
	exit(0);
}

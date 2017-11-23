#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "employee.h"

int main(int argc, char *argv[])
{
	int fd;
	struct employee record;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0640))>0)
	{
			
	}
	else
	{
		printf("open error\n");
		exit(1);
	}

	for(;;)
	{
		printf("Enter employee name <SPACE> salary: ");
		scanf("%s", record.name);
		if(record.name[0] == '.')break;
		
		scanf("%d", &record.salary);
		record.pid = getpid();
		write(fd, (char *)&record, sizeof(record));
	}
	close(fd);
	exit(0);
}


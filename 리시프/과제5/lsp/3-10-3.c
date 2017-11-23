#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "employee.h"

#define DUMMY 0

int main(int argc, char *argv[])
{
	int fd, flag, pid;
	struct employee record;
	

	if(argc < 2)
	{
		printf("Usage: %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) == -1)
	{
		printf("%s\n", argv[1]);
		exit(2);
	}

	if((flag = fcntl(fd, F_GETFL))==-1)
	{
		printf("%s\n", argv[1]);
		exit(3);
	}

	flag = fcntl(fd, F_SETFL, O_APPEND);

	pid = getpid();

	for(;;)
	{
		printf("Enter employee name: ");
		scanf("%s", record.name);
		if(record.name[0] == '.')break;

		printf("Enter employee salary: ");
		scanf("%d", &record.salary);
		record.pid = pid;

		write(fd, (char *)&record, sizeof(record));
	}

	close(fd);
	exit(0);
}


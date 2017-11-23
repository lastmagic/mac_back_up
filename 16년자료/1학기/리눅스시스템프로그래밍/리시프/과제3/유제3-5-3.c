#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "employee.h"

int main(int argc, char *argv[])
{
	int fd, recnum;
	struct employee record;

	if(argc < 2)
	{
		printf("Usage: %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY))== -1)
	{
		printf("%s\n", argv[1]);
		exit(2);
	}

	for(;;)
	{
		printf("Enter record number: ");
		scanf("%d", &recnum);

		if(recnum < 0) break;

		lseek(fd, (long)recnum*sizeof(record),SEEK_SET);

		if(read(fd, &record, sizeof(record)) >0)
			printf("Employee: %s\tSalary : %d\n", record.name, record.salary);
		else
			printf("Record %d not found\n", recnum);
	}

	close(fd);
	exit(0);
}

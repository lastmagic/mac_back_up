#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){


	char *fname = "test.txt";
	int fd;
	fd = open(fname, O_RDONLY);
	if(fd >0){
		printf("Success!\n");
		printf("Filename: %s, descriptor: %d\n", fname,fd);
	}
	else{
		printf("failed\n");
	}

	exit(0);	
}

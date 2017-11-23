#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sock;
	char message[BUF_SIZE];
	int str_len;
	struct sockaddr_in serv_adr;

    struct msgformat{
        char cmd[8];
        char content[100];
        int len;
    }msgformat;
    
    struct name{
        char name[30];
        int len;
    }name;
    
	if(argc!=4) {
		printf("Usage : %s <IP> <port> <Username>\n", argv[0]);
		exit(1);
	}
	
    sprintf(name.n, "[%s]", argv[3]);
    name.len = strlen(name.n);
    
	sock=socket(PF_INET, SOCK_STREAM, 0);   
	if(sock==-1)
		error_handling("socket() error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));
	
	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("connect() error!");
	else
		puts("Connected...........");
    
	
	while(1) 
	{
		fgets(message, BUF_SIZE, stdin);
		
		if(!strcmp(message,"@exit\n"))
			break;

		write(sock, message, strlen(message));
		str_len=read(sock, message, BUF_SIZE-1);
		message[str_len]=0;
		printf("Message from server: %s", message);
	}
   
    strcpy(message, "@exit");
    write(sock, message, strlen(message));
    shutdown(sock, SHUT_WR);
    while(1)
    {
        read(sock, message, BUF_SIZE-1);
        if(strcmp(message, "@exit")==0)
        {
            printf("get %s\n", message);
            close(sock);
        }
        
        else
            continue;
    }
    
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
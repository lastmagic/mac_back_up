#include <stdio.h> //필요한 헤더를 선언하는 부분
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

#define LS_ALL_SIG -110 //모든 데이터 통신을 진행할때 마지막에 signal을 붙여서 일반적으로 처리함.
#define SYS_CALL_SIG -111
#define SAVE_SIG -112
#define CD_SIG -113
#define EXIT_SIG -114
#define END_OF_MASSAGE_SIG -115
#define UNKNOWN_OPTION_SIG -116
#define BUF_SIZE 4096 //BUF_SIZE를 넉넉하게 잡아서 cat등에 대비함

void error_handling(char *message);
void read_routine(int sock, char *buf);
void write_routine(int sock, char *buf);


int main(int argc, char *argv[])
{
	int sock;
	int str_len;
	pid_t pid;

	char buf[BUF_SIZE]; //입&출력에 필요한 버퍼를 선언하는 부분.
	char tmp_buf[BUF_SIZE];
	char *cmd;
	char *arg;
	char sig=UNKNOWN_OPTION_SIG;

	bool normal_quit = false; //정상적으로 종료되었는지 확인하는 플래그
	struct sockaddr_in serv_adr;
	if(argc!=3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}


	sock=socket(PF_INET, SOCK_STREAM, 0); //초기화 하는 부분.
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1) // connect진행
		error_handling("connect() error!");

	printf("서버에 접속하기 위해 ID를 입력해주세요...\n"); //ID와 PASSWD를 입력받아 login 을 진행하는 부분.
	fgets(buf, BUF_SIZE, stdin);
	write(sock, buf, strlen(buf));
	printf("서버에 접속하기 위해 PASSWD를 입력해주세요...\n");
	fgets(buf, BUF_SIZE, stdin);
	write(sock, buf, strlen(buf));
	read_routine(sock ,buf);

// 서버 메세지 받는 부분 필요.

while(1)
{
	strcpy(buf,""); strcpy(tmp_buf, ""); //루프를 시작할때마다 초기화 하여 에러를 방지한다.
	fgets(buf, BUF_SIZE, stdin);
	strcpy(tmp_buf, buf);
	cmd = strtok(tmp_buf, " "); //스트링을 파싱하여 cmd, arg로 구분하여 로직을 진행한다.
	arg = strpbrk(buf, " ");

	if(strcmp(cmd, "quit")==0||strcmp(buf, "quit\n")==0)// 종료명령어를 보낸경우 서버로 종료 시그널을 보낸 후 서버로 부터 로그아웃 메세지를 받고 close한다.
	{
		write(sock, buf, strlen(buf));
		sig = EXIT_SIG;
		write(sock ,&sig, 1);
		read_routine(sock, buf);
		close(sock);
		normal_quit = true;
		break;
	}
	else if(strcmp(cmd, "ls")==0||strcmp(buf, "ls\n")==0) //ls가 진행 된 경우 파일 사이즈 및 수정날짜 등을 확인하기 위해 ls -al로 파싱해서 보낸다.
	{
		if(strcmp(buf, "ls\n")==0)
		{
			strcpy(tmp_buf, "ls -al");
			write(sock, tmp_buf, strlen(tmp_buf));
			sig = LS_ALL_SIG;
			write(sock ,&sig, 1);
			read_routine(sock, buf);
		}
		else
		{
			strcpy(tmp_buf, "ls -al");
			strcat(tmp_buf, arg);
			strcpy(buf, tmp_buf);
			write(sock, buf, strlen(buf));
			sig = LS_ALL_SIG;
			write(sock ,&sig, 1);
			read_routine(sock, buf);
		}

	}
	else if(strcmp(cmd, "save")==0) //save의 경우 파일을 서버에서 만들어서 저장하므로 파일 이름만을 보낸다.
	{
		strcpy(tmp_buf, arg);
		int j=0;
		for(j =0; j<strlen(tmp_buf)-1; j++)
		{
			tmp_buf[j] = tmp_buf[j+1];
			if(j == strlen(tmp_buf)-2)
			{
				tmp_buf[j+1] = 	0;
				break;
			}
		}
		write(sock, tmp_buf, strlen(tmp_buf)-1);//여기에서는 arg만 보내면 바로 이동 잇음.
		sig = SAVE_SIG;
		write(sock ,&sig, 1);


		while(fgets(buf, BUF_SIZE, stdin)) //파일 이름을 보낸 경우 서버에서 파일이 open으로 생성되며 이후 파일의 내용을 사용자로 부터 입력받아 "q"를 만날 때 까지 저장한다.
		{
			if(strcmp(buf, "q\n")==0)
			{
				sig = END_OF_MASSAGE_SIG;
				write(sock ,&sig, 1);
				break;
			}
			write(sock, buf, strlen(buf));
		}

		read_routine(sock, buf);
	}
	else if(strcmp(cmd, "cd") == 0) //디렉토리를 변경할 경우 서버에서 chdir함수를 사용하며 이때 path만 존재하면 되므로 path만 파싱해서 보낸다.
	{
		strcpy(tmp_buf, arg);
		int j=0;
		for(j =0; j<strlen(tmp_buf)-1; j++)
		{
			tmp_buf[j] = tmp_buf[j+1];
			if(j == strlen(tmp_buf)-2)
			{
				tmp_buf[j+1] = 	0;
				break;
			}
		}
		write(sock, tmp_buf, strlen(tmp_buf)-1);//여기에서는 arg만 보내면 바로 이동 잇음.
		sig = CD_SIG;
		write(sock ,&sig, 1);
		read_routine(sock, buf);
	}
	else if(strcmp(cmd, "cat")==0||strcmp(cmd, "rm")==0||strcmp(cmd, "mkdir")==0||strcmp(cmd,"rmdir")==0||strcmp(cmd,"cp")==0) //나머지 시스템함수의 경우 입력받은 그대로 보낸 후 서버에서 popen을 이용하면 되므로 그대로 보낸다.
	{
		write(sock, buf, strlen(buf));
		sig = SYS_CALL_SIG;
		write(sock ,&sig, 1);
		read_routine(sock, buf);
	}


}
	if(normal_quit == false) //정상종료가 아닐경우 플래그를 이용해 출력한다.
	{
		printf("Quit를 입력받아 진행된 종료가 아닙니다.\n");
		close(sock);
	}
	else
	{
		printf("프로그램이 정상적으로 종료되었습니다.\n");
	}
	return 0;
}

void read_routine(int sock, char *buf) //서버에서 보내주는 메세지는 모두 끝에 END_OF_MASSAGE_SIG가 붙어있으므로 이것을 읽을때 까지 계속해서 읽는방법을 사용한다.
{
	int str_len, i=0;

	while(1)
	{
		str_len = read(sock, &buf[i], 1);

		if(buf[i] ==END_OF_MASSAGE_SIG)
		{
			buf[i] = '\0';
			printf("%s\n", buf);
			i=0;
			break;
		}
		else
		{
			i++;
		}
	}
}

void error_handling(char *message) //에러가 발생했을때 메세지를 띄워주는 함수이다.
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

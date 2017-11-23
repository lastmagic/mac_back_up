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
void read_childproc(int sig);

struct UserAccount//계정정보를 저장하는 구조체
{
	char name[24];
	char passwd[24];
};

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock, i, index, fd; //소켓 및 for loop변수, 파일디스크립터 선언.
	struct sockaddr_in serv_adr, clnt_adr; //소켓주소 구조체 선언.
	struct UserAccount account_list[5];
	bool login =false; //로그인이 되는지 안되는지 확인하는 부분
	FILE *fp;
	chdir("/"); //프로세스마다 루트를 모두 서버루트와 동일하게 진행한다. >>따라서 실행 시 server는 root권한이 반드시 있어야 한다.

	strcpy(account_list[0].name, "Heedong"); //계정정보를 저장.
	strcpy(account_list[0].passwd, "1234");
	strcpy(account_list[1].name, "Hongdong");
	strcpy(account_list[1].passwd, "3333");
	strcpy(account_list[2].name, "SangHyun");
	strcpy(account_list[2].passwd, "4321");
	strcpy(account_list[3].name, "JuWon");
	strcpy(account_list[3].passwd, "1357");
	strcpy(account_list[4].name, "JaeSyung");
	strcpy(account_list[4].passwd, "2469");
	pid_t pid; //fork를 위한 pid
	struct sigaction act;
	socklen_t adr_sz;
	int str_len, state;
	char buf[BUF_SIZE];
	char read_buf[BUF_SIZE];
	char *temp_buf;
	char sig=-99; //sig변수를 선언하여 sig를 보낼때 사용.
	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	act.sa_handler=read_childproc; //초기화 하는 부분.
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	state=sigaction(SIGCHLD, &act, 0);
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr))==-1) // bind부분
		error_handling("bind() error");
	if(listen(serv_sock, 5)==-1)//listen 부분.
		error_handling("listen() error");

	while(1)
	{
		login = false;
		index = -1;
		adr_sz=sizeof(clnt_adr);
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
		if(clnt_sock==-1)
			continue;
		else
			printf("새로운 클라이언트의 ID, PASSWD확인중...\n"); //로그인 기능 구현부분.

		pid=fork();
		if(pid==-1) //오류인 부분
		{
			close(clnt_sock);
			continue;
		}
		if(pid==0) //자식의 경우(serv_sock을 닫고 clnt_sock만 가지고 통신진행)
		{
			close(serv_sock);
			str_len=read(clnt_sock, buf, sizeof(buf));
			buf[str_len-1] ='\0';

			for(i=0; i<5; i++) //id 와 passwd를 확인하는 부분
			{
				if(!strcmp(buf, account_list[i].name))
				{
					printf("아이디가 일치합니다!\n");
						str_len=read(clnt_sock, buf, sizeof(buf));
					buf[str_len-1] ='\0';
					if(!strcmp(buf, account_list[i].passwd))
					{
						printf("비밀번호도 일치합니다!\n");
						login =true;
						index = i;
						break;
					}
					else
					{
						break;
					}
				}
			}
			if(!login)
			{
				write(clnt_sock, "ID or PassWd 가 잘못되었습니다. 확인후 다시 로그인 해주세요", strlen("ID or PassWd 가 잘못되었습니다. 확인후 다시 로그인 해주세요"));
				close(clnt_sock);
				continue;
			}

			printf("%s 유저가 접속에 성공하였습니다.\n", account_list[index].name); //로그인에 성공 한 경우 로그인 정보를 클라에게 뿌려준다.
			sig = END_OF_MASSAGE_SIG;
			write(clnt_sock, account_list[index].name, strlen(account_list[index].name));
			write(clnt_sock, " 님이 로그인 하셨습니다.", strlen(" 님이 로그인 하셨습니다."));
			write(clnt_sock, &sig, 1);


			//여기부터 system함수 들어가는 로직이 필요함.
			i = 0;

			while((str_len=read(clnt_sock, &buf[i], 1))>0) //무조건 size 1씩 읽으면서 signal인지 확인한다.
			{
				// printf("현재 temp_buf = %c\n",  buf[i]);
				// printf("while loop들어옴\n");
				if(buf[i] < 0) //0보다 작은경우는 sig만 가능하므로, 이때 각 분기에 따라 진행한다.
				{
					if(buf[i] == SYS_CALL_SIG)
					{
						buf[i] = '\0';
						fp = popen(buf, "r");
						if(fp == NULL)
						{
							perror("popen error");
							exit(1);
						}
						else
						{
							while(fgets(buf, BUF_SIZE, fp))
							{
								write(clnt_sock, buf, strlen(buf));
								printf("현재 buf  = %s\n", buf);
							}

							sig = END_OF_MASSAGE_SIG;
							write(clnt_sock, &sig, 1);
							pclose(fp);
							strcpy(buf, "");
							i=0;
							continue;
						}
					}
					else if(buf[i] == LS_ALL_SIG)
					{
						buf[i] = '\0';
						fp = popen(buf, "r");
						if(fp == NULL)
						{
							perror("popen error");
							exit(1);
						}
						else
						{
							while(fgets(buf, BUF_SIZE, fp))
							{
								write(clnt_sock, buf, strlen(buf));
							}

							sig = END_OF_MASSAGE_SIG;
							write(clnt_sock, &sig, 1);
							pclose(fp);
							strcpy(buf, "");
							i=0;
							printf("LS_ALL_SIG OK!\n");
							continue;
						}
					}
					else if(buf[i] == SAVE_SIG)
					{
						buf[i] = '\0';
						printf("buf=%s\n", buf);
						fd = open(buf, O_CREAT|O_APPEND|O_RDWR, 0644);
						i =0;
						while((str_len=read(clnt_sock, &buf[i], 1))>0)
						{
							if(buf[i] == END_OF_MASSAGE_SIG)
							{
								buf[i] = '\0';
								write(fd, buf, strlen(buf));
								break;
							}
							else
							{
								i++;
							}
						}
						close(fd);
						strcpy(buf, "쓰기 성공!\n");
						sig = END_OF_MASSAGE_SIG;
						write(clnt_sock, buf, strlen(buf));
						write(clnt_sock, &sig, 1);
						strcpy(buf, "");
						i=0;
						printf("SAVE_SIG OK!\n");
						continue;

					}
					else if(buf[i] == CD_SIG)
					{
							buf[i] = '\0';
							printf("buf=%s\n", buf);
							int cd_flag = chdir(buf);
							if(cd_flag == 0)
							{
								strcpy(buf, "CD성공\n");
							}
							else
							{
								strcpy(buf, "CD실패\n");
							}
							sig = END_OF_MASSAGE_SIG;
							write(clnt_sock, buf, strlen(buf));
							write(clnt_sock, &sig, 1);
							printf("%s", buf);
							strcpy(buf, "");
							i=0;
							continue;
					}
					else if(buf[i] == EXIT_SIG)
					{
						printf("%s유저가 접속을 종료하였습니다.\n", account_list[index].name);
						strcpy(buf, account_list[index].name);
						strcat(buf, "님이 로그아웃 하셨습니다.\n");
						sig = END_OF_MASSAGE_SIG;
						write(clnt_sock, buf, strlen(buf));
						write(clnt_sock, &sig, 1);
						close(clnt_sock);
					}
				}
				else //signal이 아닌경우 데이터로서 들어 온 것이므로 버퍼에 저장된 값을 확인하고 i를 증가시킨다.
				{
					printf("Else로 들어왔다.buf = %c\n", buf[i]);
					i++;
				}
			}

			close(clnt_sock);
			puts("client disconnected...");

			return 0;
		}
		else
			close(clnt_sock);
	}
	close(serv_sock);
	return 0;
}

void read_childproc(int sig)
{
	pid_t pid;
	int status;
	pid=waitpid(-1, &status, WNOHANG);
	printf("removed proc id: %d \n", pid);
}
void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

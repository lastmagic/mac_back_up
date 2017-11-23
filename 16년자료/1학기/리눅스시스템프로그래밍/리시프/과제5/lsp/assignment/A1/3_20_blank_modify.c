#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#include <fcntl.h>

//#define DEBUG 1
#define BUFSIZE 200

off_t offset;

void ssu_history(int argc, char *argv[])
{
	int i=0;
	int num=0;
	int fd;
	int flag=0;
	char buf[BUFSIZE];
	bool flag_c =false;
	bool flag_r =false;
	bool flag_n =false;
	bool flag_unknown =false;
	char *temp=NULL;
	for(i=1; i<argc; i++)
	{
		if((temp = strchr(argv[i], 'c'))!=NULL)
			flag_c = true;
		if((temp =strchr(argv[i], 'r'))!=NULL)
			flag_r =true;
		if((temp =strchr(argv[i],
						'n'))!=NULL&&(temp=strchr(argv[i],'c'))==NULL&&((temp=strchr(argv[i],'r'))==NULL))
		{

			if((temp = strpbrk(argv[i], "abdefghijklmopqstuvwxyz"))==NULL)
			{
				flag_n =true;
				num = atoi(argv[++i]); 
				continue;
			}
		}
		//crn을 제외한 문자를 입력받았을때 flag 를 바꿔주는 if loop 필요.
		if((temp = strpbrk(argv[i], "abdefghijklmopqstuvwxyz"))!=NULL)
		{
			flag_unknown = true;
			break;
		}
	}

#ifdef DEBUG
	printf("ssu_history!\n");
	printf("flag_c =%d, flag_r = %d, flag_n = %d\n", flag_c,flag_r,flag_n);
	printf("num =%d\n", num);
#endif
	if((flag_unknown == true)||(num < 0)||(num>100))
	{
		printf("unknown option %s\n", argv[i]);
		printf("-c: print number of each history\n");
		printf("-n: NUMBER: print history maximum NUMBER\n");
		printf("-r: print history in reverse order\n");
	}

	fd = open("store.txt", O_CREAT|O_RDONLY, 0644);
	offset = lseek(fd, 0, SEEK_CUR);

	if(flag_n == true)
		num = num;
	else
		num = 100;

	if(flag_r == true)
	{
		offset = lseek(fd, -sizeof(buf), SEEK_END);
		for(i=0; i<num; i++)	
		{
			flag = read(fd, buf, sizeof(buf));
			if(flag == -1)
			{
				printf("ssu_history read error\n");
				break;
			}
			if(flag == 0)
				break;
			printf("%s\n", buf);
			if((offset = lseek(fd, -2*sizeof(buf), SEEK_CUR))==-1)
				break;
		}
	}
	else
	{
		for(i=0; i<num; i++)
		{
			flag = read(fd, buf, sizeof(buf));
			if(flag == -1)
			{
				printf("ssu_history read error\n");
				break;
			}
			if(flag == 0)
				break;
			printf("%s\n", buf);
		}
	}
}

void ssu_grep(int argc, char *argv[])
{

	int i=0;
	int num=0;
	int fd;
	int flag=0;
	char buf[BUFSIZE];
	char *name;
	bool flag_d =false;
	bool flag_e =false;
	bool flag_i =false;
	bool flag_n =false;
	bool flag_r =false;
	bool flag_unknown =false;
	char *temp=NULL;
	for(i=1; i<argc; i++)
	{
		if((temp = strchr(argv[i], 'd'))!=NULL)
			flag_d = true;
		if((temp =strchr(argv[i], 'i'))!=NULL)
			flag_i =true;
		if((temp =strchr(argv[i], 'n'))!=NULL)
			flag_n =true;
		if((temp =strchr(argv[i], 'r'))!=NULL)
			flag_r =true;
		if((temp =strchr(argv[i],
						'e'))!=NULL&&(temp=strchr(argv[i],'d'))==NULL&&((temp=strchr(argv[i],'i'))==NULL)&&(temp=strchr(argv[i],
							'n'))==NULL&&(temp=strchr(argv[i],'r'))==NULL)
		{

			if((temp = strpbrk(argv[i], "abcfghjklmopqstuvwxyz"))==NULL)
			{
				flag_e =true;
				name = argv[++i]; 
				continue;
			}
		}
		//crn을 제외한 문자를 입력받았을때 flag 를 바꿔주는 if loop 필요.
		if((temp = strpbrk(argv[i], "abcfghjklmopqstuvwxyz"))!=NULL)
		{
			flag_unknown = true;
			break;
		}
	}

#ifdef DEBUG
	printf("ssu_grep!\n");
	printf("flag_d =%d, flag_e = %d, flag_i = %d, flag_n =%d, flag_r =	%d\n", flag_d,flag_e,flag_i, flag_n, flag_r);
	printf("name =%s\n", name);
#endif
	if((flag_unknown == true)||(argc < 3))
	{
		printf("Usage: ssu_grep STRING FILE... [OPTION]\n");
		printf("-d: delete file that has STRING\n");
		printf("-e: NAME: don't check file that includes NAME in file name\n");
		printf("-i: ignore case distinctions\n");
		printf("-n: print line number with output lines\n");
		printf("-r: check all file in directory\n");
	}
}

struct ssu_function
{
	char *cmd;
	void (*func)(int ,char* []);
};

struct ssu_function cmdList[] = 
{
	{"ssu_history", ssu_history},
	{"ssu_grep", ssu_grep},
	{NULL}
};

void flush(char array[], char *ptn[],int size1, int size2)
{
	int i=0;
	for(i =0; i<size1; i++)
	{
		array[i] = '\0';
	}
	for(i =0; i<size2; i++)
	{
		ptn[i] = NULL;
	}
}

int main(int argc, char *argv[])
{
	char arg[BUFSIZE];//사용자로부터 입력받는 버퍼
	char tmp[BUFSIZE];
	char system_buf[BUFSIZE];
	char *str[11];//버퍼에서 토큰으로 구분해 받는 새로운 버퍼
	int arg_count;
	int i;
	int fd;
	bool flag =false; //정상적인 값이 입력되었는지 확인하는 flag이다
	struct timeval curTime;
	struct timeval lastTime;
	system("clear");
	while(1)
	{
		flush(arg,str,100,10);
		arg_count = 0;
		printf("20142397 $ ");
		fgets(arg, sizeof(arg), stdin);
		if(arg[0]=='\n')
			continue;
		else if((str[10] = strchr(arg, '\n'))!= NULL)
			*str[10] ='\0';
		strcpy(system_buf,arg);
		printf("point a =%s\n", system_buf);
		str[10] = strtok(arg, " \t");
		str[0] = str[10];
#ifdef DEBUG
		printf("token %d = %s\n", 0, str[0]);
#endif
		while(str[10]!=NULL) // 10개 로직수정
		{
			arg_count++;
			if(arg_count >= 10)
			{
				printf("input less than or equal to 10 argument\n");
				for(i = 0; i<11; i++)
				{
					str[i] = NULL;
					printf("%d: %s\n", i, str[i]);

				}
				flag = false;
				break;
			}
			else
			{
				str[10] = strtok(NULL, " \t");
				str[arg_count] = str[10];
#ifdef 	DEBUG
				printf("token %d = %s\n", arg_count, str[arg_count]);
#endif
				flag = true;
			}
		}
	
		for(i =0 ;i<arg_count; i++) /*arg를 붙일경우 abort error가 발생함*/
		{
			strcat(tmp, str[i]);
		}
#ifdef DEBUG
		printf("arg before = %s\n", tmp);
#endif
		fd = open("store.txt", O_CREAT|O_RDWR|O_APPEND, 0644);
		offset = lseek(fd, 0, SEEK_END);
		write(fd, tmp, sizeof(tmp));
		close(fd);
		strcpy(tmp, "");
#ifdef DEBUG
		printf("tmp after=%s\n", tmp);
#endif
		if(flag == true)
		{
			if(strcmp(str[0], "ssu_history")==0)
			{
				cmdList[0].func(arg_count, str);
			}
			else if(strcmp(str[0], "ssu_grep")==0)
			{
				cmdList[1].func(arg_count, str);
			}
			else
			{
				gettimeofday(&curTime, NULL);
				system(system_buf);
				gettimeofday(&lastTime, NULL); /*시간 로직은 틀림 함수를
												 만들거나 해야할 듯 */
				printf("Time: %ld.000%d\n",
						lastTime.tv_sec-curTime.tv_sec,(lastTime.tv_usec-curTime.tv_usec));

				continue;
			}
		}
		else
			continue;
	}

}

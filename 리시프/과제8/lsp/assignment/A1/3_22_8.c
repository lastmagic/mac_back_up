#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
//#define DEBUG 1
#define BUFSIZE 200

off_t offset;
struct c_array
{
	char buf[BUFSIZE];
	int cnt;
	bool check;
};
void ssu_history(int argc, char *argv[])
{
	struct c_array c_array[100];
	int i=0;
	int j=0;
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
		if((temp = strchr(argv[i], 'c'))!=NULL&&(temp = strchr(argv[i], '-'))!=NULL)
			flag_c = true;
		if((temp =strchr(argv[i], 'r'))!=NULL&&(temp = strchr(argv[i], '-'))!=NULL)
			flag_r =true;
		if((temp =strchr(argv[i],
						'n'))!=NULL&&(temp=strchr(argv[i],'c'))==NULL&&((temp=strchr(argv[i],'r'))==NULL)&&(temp = strchr(argv[i], '-'))!=NULL)
		{

			if((temp = strpbrk(argv[i], "abdefghijklmopqstuvwxyz"))==NULL)
			{
				flag_n =true;
				if(i == argc-1)
				{
					flag_unknown = true;
					break;
				}
				else
					num = atoi(argv[++i]);

				if(num == 0)
				{
					flag_unknown =true;
					break;
				}
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
		return;
	}

	if(flag_c == true)// if i can not fix this problem, then i have to remove this.
	{
		fd = open("store.txt", O_RDONLY);
		for(i=0; i<100; i++)
		{
			if(read(fd, c_array[i].buf, sizeof(buf))==0)
				break;
			c_array[i].cnt =-1;
			c_array[i].check = false;
			printf("c_array[%d] = %s\n", i, c_array[i].buf);
		}

		for(i=0; i<100; i++)
		{
			for(j=0; j<100; j++)
			{
			}
		}
	}
	else
	{
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
}

void ssu_grep(int argc, char *argv[])
{

	int i=0;
	int j=0;
	int index=0;
	int ori_index=0;
	int fd;
	int read_index;
	int cnt=0;
	bool flag_d =false;
	bool flag_e =false;
	bool flag_i =false;
	bool flag_n =false;
	bool flag_r =false;
	bool flag_unknown =false;
	bool flag_first = false;
	char *name;
	char fname[500][200];
	char string[100];
	char *temp=NULL;
	char buf[2048];
	char buf2[2048];
	char fname_cat[200];
	char fname_cat2[200];
	FILE *fptr;
	struct stat file_info;
	struct dirent *dir_entry;
	DIR *dir_info;

	for(i=0; i<argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	strcpy(string, argv[1]);
	for(i=2; i<argc; i++)
	{
		if((temp = strchr(argv[i], 'd'))!=NULL&&(temp = strchr(argv[i], '-'))!=NULL)
			flag_d = true;
		if((temp = strchr(argv[i], 'i'))!=NULL&&(temp = strchr(argv[i], '-'))!=NULL)
			flag_i =true;
		if((temp = strchr(argv[i], 'n'))!=NULL&&(temp = strchr(argv[i], '-'))!=NULL)
			flag_n =true;
		if((temp = strchr(argv[i], 'r'))!=NULL&&(temp = strchr(argv[i], '-'))!=NULL)
			flag_r =true;
		if((temp = strpbrk(argv[i], "abcfghjklmopqstuvwxyz"))!=NULL&&(temp = strchr(argv[i], '-'))!=NULL)
			flag_unknown = true;
		if((temp = strchr(argv[i], '-'))==NULL)
		{
			strcpy(fname[index], argv[i]);
			ori_index = ++index;
		}
		if((temp = strchr(argv[i], 'e'))!=NULL&&(temp = strchr(argv[i], '-'))!=NULL)
		{
			if((temp = strpbrk(argv[i], "abcdfghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ"))==NULL)
			{
				if(i == argc-1)
				{
					flag_unknown = true;
					break;
				}
				else
				{
					flag_e = true;
					name = argv[++i];
				}
			}
			else
			{
				flag_unknown = true;
				break;
			}
		}
	}


#ifdef DEBUG
	printf("ssu_grep!\n");
	printf("flag_d =%d, flag_e = %d, flag_i = %d, flag_n =%d, flag_r =	%d flag_u = %d\n", flag_d,flag_e,flag_i, flag_n, flag_r, flag_unknown);
	printf("name =%s\n", name);
	for(i=0; i<index; i++)
	{
		printf("fname[%d] = %s\n", i, fname[i]);
	}
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

	for(i=0; i<index; i++)
	{
		cnt = 0;
		if(flag_r == true)
		{
			if(stat(fname[i], &file_info)<0)
			{
				printf("stat() error, i = %d\n", i);
				continue;
			}
			if(S_ISDIR(file_info.st_mode))
			{
				if(i<ori_index)
				{
					if(strcmp(fname[index], "..")==0)
						continue;
					if(flag_first == true)
					{
						flag_first = false;
					}
					else
					{
						if(strcmp(fname[index], ".")==0)
							continue;
					}
				//	strcpy(fname_cat, "./");
				//	strcat(fname_cat, fname[i]);
				//	strcpy(fname[i], fname_cat);
					dir_info = opendir(fname[i]);
					printf("%s is directory\n",  fname[i]);
					for(;;)
					{
						dir_entry = readdir(dir_info);
						if(dir_entry == NULL)
							break;
						strcpy(fname_cat, "/");
						strcat(fname_cat, dir_entry->d_name);
						strcpy(fname_cat2, fname[i]);
						strcat(fname_cat2, fname_cat);
						strcpy(fname[index], fname_cat2);
						stat(fname[index], &file_info);
						if(S_ISDIR(file_info.st_mode))
						{
							printf("%s is directory\n", fname[index]);
							index++;
						}
					}

				}
				else
				{
					if(strcmp(fname[i], ".")==0||strcmp(fname[i], "..")==0)
						continue;
				}
				if((dir_info = opendir(fname[i]))==NULL)
				{
					printf("dir open error!, fname[%d] =%s\n", i, fname[i]);
				}
				else
				{
					for(;;)
					{
						dir_entry = readdir(dir_info);
						if(dir_entry == NULL)
							break;
						strcpy(fname[index++], dir_entry->d_name);
						printf("in flag_r fname[%d] = %s\n", index, fname[index]);
					}
					closedir(dir_info);

				}
			}
			else if(S_ISREG(file_info.st_mode))
			{

				if(flag_e == true)
				{
					if(strstr(fname[i], name)!=NULL)
						continue;
				}

				if((fd = open(fname[i], O_RDWR))<0)
				{
					printf("file open error, fname[%d] = %s\n", i, fname[i]);
					continue;
				}
				fptr = fopen(fname[i], "r");
				for(;;)
				{
					temp = fgets(buf, sizeof(buf), fptr);
					if(temp == NULL)
						break;
					cnt++;
					if(flag_i == true)
					{
						strcpy(buf2, buf);
						for(j=0; j<2048; j++)
						{
							if(buf[j]=='\n')
								break;
							buf[j]=tolower(buf[j]);
						}
						for(j=0; j<100; j++)
						{
							string[j] = tolower(string[j]);
						}
						if(strstr(buf, string)!=NULL)
						{
							if(flag_n == true)
							{
								printf("%d %s:%s", cnt, fname[i], buf2);
							}
							else
								printf("%s:%s", fname[i], buf2);

						}
					}
					else
					{
						if(strstr(buf, string)!=NULL)
						{
							if(flag_n == true)
							{
								printf("%d %s:%s", cnt,fname[i],buf);
							}
							else
								printf("%s:%s",fname[i],buf);
						}

					}
				}
			}
			else if(S_ISCHR(file_info.st_mode))
			{
			}
			else if(S_ISBLK(file_info.st_mode))
			{
			}
			else if(S_ISFIFO(file_info.st_mode))
			{
			}
			//else if(S_ISLINK(file_info.st_mode))
		}
	}
	for(i =0; i<index; i++)
	{
		cnt =0;
		if(flag_r == false)
		{

			if(stat(fname[i], &file_info)<0)
			{
				printf("stat error fname[%d] = %s\n", i, fname[i]);
				continue;
			}
			if(S_ISDIR(file_info.st_mode))
			{
				printf("binary file %s matches\n", fname[i]);
			}
			else if(S_ISREG(file_info.st_mode))
			{
			}
			else if(S_ISCHR(file_info.st_mode))
			{
				printf("%s is character special file\n", fname[i]);
			}
			else if(S_ISBLK(file_info.st_mode))
			{
				printf("%s is is block special file\n", fname[1]);
			}
			else if(S_ISFIFO(file_info.st_mode))
			{
				printf("%s is FIFO\n", fname[1]);
			}
			//else if(S_ISLINK(file_info.st_mode))
			{
			//	printf("%s is directory\n", fname[1]);
			}
			if(flag_e == true)
			{
				if(strstr(fname[i], name)!=NULL)
					continue;
			}

			if((fd = open(fname[i], O_RDWR))<0)
			{
				printf("file open error, fname[%d] = %s\n", i, fname[i]);
				continue;
			}
			fptr = fopen(fname[i], "r");
			for(;;)
			{
				temp = fgets(buf, sizeof(buf), fptr);
				if(temp == NULL)
					break;
				cnt++;
				if(flag_i == true)
				{
					strcpy(buf2, buf);
					for(j=0; j<2048; j++)
					{
						if(buf[j]=='\n')
							break;
						buf[j]=tolower(buf[j]);
					}
					for(j=0; j<100; j++)
					{
						string[j] = tolower(string[j]);
					}
					if(strstr(buf, string)!=NULL)
					{
						if(flag_n == true)
						{
							printf("%d %s:%s", cnt, fname[i], buf2);
						}
						else
							printf("%s:%s", fname[i], buf2);

					}
				}
				else
				{
					if(strstr(buf, string)!=NULL)
					{
						if(flag_n == true)
						{
							printf("%d %s:%s", cnt,fname[i],buf);
						}
						else
							printf("%s:%s",fname[i],buf);
					}

				}
			}
		}
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
	char tmp[BUFSIZE];//if i use arg > abort error accur. store parsed cmd.
	char system_buf[BUFSIZE];
	char read_buf[100][BUFSIZE];	//Read and check, cmd <100
	char *str[11];//버퍼에서 토큰으로 구분해 받는 새로운 버퍼
	int arg_count;
	int i;
	int fd;
	int buf_index=0;
	FILE *inputfile;
	bool flag =false; //정상적인 값이 입력되었는지 확인하는 flag이다
	struct timeval curTime;
	struct timeval lastTime;
	double time;
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
		//		printf("point a =%s\n", system_buf);
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
		/*fd = open("store.txt", O_CREAT|O_RDWR|O_APPEND, 0644);
		  offset = lseek(fd, 0, SEEK_END);
		  write(fd, tmp, sizeof(tmp));
		  close(fd);*/
		fd = open("store.txt", O_CREAT|O_RDWR, 0644);
		offset = lseek(fd, 0, SEEK_SET);
		for(i=0; i<100; i++)
		{
			buf_index = read(fd, read_buf[i], sizeof(tmp));
			//			printf("read_buf[%d] = %s\n", i, read_buf[i]);
			if(buf_index == 0)
			{
				buf_index = i;
				break;
			}
		}
		close(fd);
		//	printf("buf_index = %d\n", buf_index);
		if(buf_index == 200)
		{
			fd = open("store.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);
			lseek(fd, 0, SEEK_SET);
			for(i=1; i<100; i++)
			{
				//				printf("write_buf[%d] = %s\n", i, read_buf[i]);
				write(fd, read_buf[i], sizeof(tmp));
				lseek(fd, 0, SEEK_END);
			}
			lseek(fd, 0, SEEK_END);
			write(fd, tmp, sizeof(tmp));
		}
		else
		{
			fd = open("store.txt", O_RDWR|O_CREAT, 0644);
			lseek(fd, 0, SEEK_END);
			write(fd, tmp, sizeof(tmp));
		}
		close(fd);
		strcpy(tmp, "");
#ifdef DEBUG
		printf("tmp after=%s\n", tmp);
#endif
		if(flag == true)
		{
			if(strcmp(str[0], "ssu_history")==0)
			{
				gettimeofday(&curTime, NULL);
				cmdList[0].func(arg_count, str);
				gettimeofday(&lastTime, NULL); 
				time = ((double)(lastTime.tv_usec-curTime.tv_usec)/1000)/1000;
				printf("Time:%lf\n", time);
			}
			else if(strcmp(str[0], "ssu_grep")==0)
			{
				gettimeofday(&curTime, NULL);
				cmdList[1].func(arg_count, str);
				gettimeofday(&lastTime, NULL); 
				time = ((double)(lastTime.tv_usec-curTime.tv_usec)/1000)/1000;
				printf("Time:%lf\n", time);
			}
			else
			{
				gettimeofday(&curTime, NULL);
				system(system_buf);
				gettimeofday(&lastTime, NULL); /*시간 로직은 틀림 함수를
												 만들거나 해야할 듯 */
				time = ((double)(lastTime.tv_usec-curTime.tv_usec)/1000)/1000;
				printf("Time:%lf\n", time);
				continue;
			}
		}
		else
			continue;
	}

}

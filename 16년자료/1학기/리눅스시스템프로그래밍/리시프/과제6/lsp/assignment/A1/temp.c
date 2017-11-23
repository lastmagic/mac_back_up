#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>

/*
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
 */
int main(int argc, char *argv[])
{
	char arg[100];//사용자로부터 입력받는 버퍼
	char *str[10];//버퍼에서 토큰으로 구분해 받는 새로운 버퍼
	int arg_count;
	int i;
	bool flag =false; //정상적인 값이 입력되었는지 확인하는 flag이다
	struct timeval curTime;
	struct timeval lastTime;
	system("clear");
	while(1)
	{
		arg_count = 0;
		printf("20142397 $ ");
		fgets(arg, sizeof(arg), stdin);
		if(arg[0]=='\n')
			continue;
		str[arg_count] = strtok(arg, " \t");
		printf("token %d = %s\n", arg_count, str[arg_count]);
		printf("pointB\n");
		for(i=0; i<9; i++) // 10개 로직수정
		{
			arg_count++;
			if(arg_count >= 10)
			{
				printf("input less than or equal to 10 argument\n");
				for(i = 0; i<10; i++)
				{
					str[i] = NULL;
					printf("%d: %s\n", i, str[i]);
				}
				flag = false;
				break;
			}
			else
			{
				str[arg_count] = strtok(NULL, " \t");
				printf("token %d = %s\n", arg_count, str[arg_count]);
				flag = true;
			}
		}
		printf("pointA\n");

		if(flag == true)
		{
			if(strcmp(str[0],"ls")==0)
			{
				gettimeofday(&curTime, NULL);
				system("ls");
				gettimeofday(&lastTime, NULL); /*시간 로직은 틀림 함수를
												 만들거나 해야할 듯 */
				printf("Time: %ld.000%d\n",
						lastTime.tv_sec-curTime.tv_sec,(lastTime.tv_usec-curTime.tv_usec));
			}	
		}
	}

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void ssu_history(int, char*temp []);
void ssu_grep(int, char*po []);


struct ssu_function{
	char* cmd;
	void (*func)(int, char* []); //structure

	};
struct ssu_function cmdList[]={
	{"ssu_history",ssu_history},
	{"ssu_grep",ssu_grep},
	{NULL}
	};

FILE *fp;

int main()
{

	while(1)
	{
		char str[100]={0}; // start cdm save 
		char *buf;	//posing buf		
		char *temp[100]={0};//posing save
		int i, tok_count=0; // ' ' divide
		int j=0; //strcat
		char catstr[100]={0}; //strcat
		
		fp = fopen("test","a+");

		printf("20142363 $ ");
		fgets(str,sizeof(str),stdin);
		str[strlen(str)-1] = '\0'; //\0 rm

		buf = strtok(str, " "); //posing

		while(buf)
		{

			temp[tok_count]=buf;
			tok_count++;
			buf = strtok(NULL, " ");


			if(tok_count>10) //tok>10 error
				printf("error!");
		
		}
	
		if(!strcmp(temp[0],cmdList[0].cmd))  //history
		{
			for(j=0;j<tok_count;j++)
			{
				strcat(catstr,temp[j]);
				strcat(catstr," ");
			}
			strcat(catstr,"\n");
		
			fputs(catstr,fp);
		
			fflush(stdout);
			fclose(fp);
			printf("%s %s %s %s\n",temp[0],temp[1],temp[2],temp[3]);
			ssu_history(tok_count,temp);
		}

		else if(!strcmp(temp[0],cmdList[1].cmd)) //gerp
		{
		}
		else   //eslse cmd
		{	
			for(j=0;j<tok_count;j++)
			{
				strcat(catstr,temp[j]);
				strcat(catstr," ");
			
			}
			strcat(catstr,"\n");
			fputs(catstr,fp);//cmd save
			fflush(stdout);
			fclose(fp);
			system(catstr);	//system cmd
		}

	}
}	


void ssu_history(int tok_count, char* temp[]){
	char *hisarr[1001]={0};
	char *block;
	int k=0;

	fp = fopen("test","a+");
	int fd = fileno(fp);
	lseek(fd,0,SEEK_SET);
	
    printf("sd");
	for(;;)
	{

	block = calloc(100,1);
    printf("sd");
	if(fgets(block,100,fp)!=0)
		break;
	
	hisarr[k]=block;
	k++;
	}

	printf("%s",hisarr[0]);
	printf("%s\n",hisarr[1]);
}

		


	
void ssu_grep(int sd, char* po[]){
}

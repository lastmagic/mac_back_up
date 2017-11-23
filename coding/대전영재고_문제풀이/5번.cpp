#include <stdio.h>
#include <stdlib.h>
void reverse(char *arr)
{
	int len=0;
	int top=-1;
	int j=0;
	char *tmp = (char*)malloc(sizeof(char)*100); //임시배열 동적할당
	char *stack = (char*)malloc(sizeof(char)*100); //stack배열 동적할당
	while(arr[len]!='\0') // 문자열 길이구하기
		len++;
	for(int i=0; i<=len ;i++) //문자열 복사
	{
		*(tmp+i) = *(arr+i);
	}

	for(int i=len-1; i>=0; i--) //문자열을 스택에 넣으면서
	{
		if(*(tmp+i)!=' ') // 공백문자가 아닌 경우 스택에 추가
		{
			*(stack+(++top)) = *(tmp+i);
		}
		else //공백문자인 경우 스택을 비워주면서 출력
		{
			while(top>=0)
			{
				*(arr+(j++)) = *(stack+(top--));
			}
			*(arr+(j++)) = ' ';
		}
	}
	while(top>=0)//위에 반복문 마지막이 공백문자가 아닌경우로 끝날경우 스택에 남아있으므로 스택을 비워줌
	{
		*(arr+(j++)) = *(stack+(top--));
	}
	*(arr+j) = '\0'; //문자열 끝을 나타내기위해 널문자 추가
}
int main(void)
{
	char buf[100]; //문자열을 입력받을 배열
	gets(buf); //문자열 입력
	printf("before: %s\n", buf);//함수호출 전 문자열
	reverse(buf); //함수호출로 buf배열 바꿈
	printf("after: %s\n", buf);//함수호출 후 문자열
}

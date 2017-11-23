#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void reverse(char *arr)
{
	int len=0;
	int top=-1;
	int j=0;
	char *b = (char*)malloc(sizeof(char)*100);
	char *stack = (char*)malloc(sizeof(char)*100);
	while(arr[len]!='\0')
		len++;
	for(int i=0; i<=len ;i++)
	{
		b[i] = arr[i];
	}

	for(int i=len-1; i>=0; i--)
	{
		if(b[i]!=' ')
		{
			stack[++top] = b[i];
		}
		else
		{
			while(top>=0)
			{
				arr[j++] = stack[top--];
			}
			arr[j++] = ' ';
		}
	}
	if(top>=0)
	{
		while(top>=0)
		{
			arr[j++] = stack[top--];
		}
	}
	arr[j] = '\0';
}
int main(void)
{
	char buf[100];
	gets(buf);
	cout << "before: " << buf <<"\n";
	reverse(buf);
	cout << "after: " << buf << "\n";

}

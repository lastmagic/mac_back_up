#include <stdio.h>
#include <stdlib.h>
void DecToN(int n, int num)
{
  int len=0,i=0;
  int tmp[100];
  char ans[100];
  while(num)
  {
    tmp[len] = num%n;
    num = num/n;
    len++;
  }
  for(int j=0; j<len; j++)
  {
    ans[j] = tmp[len-j-1];
  }
  for(int i=0; i<len; i++)
  {
    printf("%d", ans[i]);
  }
}
int main(int argc, char const *argv[]) {
  int n; //n진수
  int num; //n진수 숫자표현
  scanf("%d", &n);
  scanf("%d", &num);
  DecToN(n, num);
  return 0;
}

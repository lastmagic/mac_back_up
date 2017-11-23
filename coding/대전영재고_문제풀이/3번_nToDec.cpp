#include <stdio.h>
#include <stdlib.h>
void nToDec(int n, char *num)
{
  int len=0;
  int ans=0;
  while(num[len]!='\0')
    len++;

  for(int i=0; i<len ; i++)
  {
    ans = ans*n + (num[i]-'0');
  }
  printf("%d\n", ans);
}
int main(int argc, char const *argv[]) {
  int n; //n진수
  char num[100]; //숫자
  scanf("%d", &n);
  scanf("%s", num);
  nToDec(n, num);
  return 0;
}

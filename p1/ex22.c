#include<stdio.h>

int main(void)
{
  char c;
  int n,i;
  
  printf("entra un int: ");
  scanf("%d",&n);

  while(getchar()!='\n'); /*espero a llegir el RET*/

  printf("entra un char: ");
  scanf("%c",&c);

  for (i=0;i<n;i=i+1)
    {
      printf("%c",c);
    }
  printf("\n");
  return 0;
}

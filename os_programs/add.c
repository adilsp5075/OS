#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  int n1,n2;
  printf("Welcome to the another program\n");
  printf("______________________________\n");
  printf("\n");
  printf("Enter a number\n");
  scanf("%d",&n1);
  printf("Enter an another number\n");
  scanf("%d",&n2);
  printf("The sum of the numbers = %d\n",(n1+n2));
  printf("exiting program\n");
  printf("______________________________\n");
  fflush(stdout);
  return 0;
}

#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define FILE "./textfile.txt"

void main()
{
  char a[100];
  int fr,choice =0;
  fr = open(FILE,O_CREAT|O_RDWR);
  if (fr > 0)
  {
    printf("___________________\n");
    printf("File %s created\n",FILE);
    printf("Enter some data\n");
    printf("___________________\n");
    do
    {
      fflush(stdin);
      printf("Enter datas to the file and enter FINISH to stop\n");
      gets(a);
      if(strcmp(a,"FINISH")!= 0)
      {
        if(strlen(a) > 0)
        {
          write(fr,a,strlen(a));
          write(fr,"\n",1);
        }
      }
      else
      {
        choice++;
      }
    }
    while(choice == 0);
    lseek(fr,0,SEEK_SET);
    strcpy(a,"");
    printf("read datas from file\n");
    do
    {
      if(read(fr,a,100) > 0)
      {
        printf("%s\n",a);
        strcpy(a,"");
        if(read(fr,a,100) < 100)
        {
          choice++;
        }
      }
    }
    while(choice > 0);
    fflush(stdout);
    close(fr);
  }
}

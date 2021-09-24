#include<stdio.h>
#include<dirent.h>
#include <sys/stat.h>
void main()
{
  struct dirent *dt;
  struct stat s;
  DIR *dr=opendir(".");
  if(dr==NULL)
  {
    printf("Error");
  }
  else
  {
    while((dt=readdir(dr))!=NULL)
    {
      printf("file_name : %s\n",dt->d_name);
      if(stat(dt->d_name,&s)!=-1)
      {
        printf("file details\n");
        printf("File_Size : %d Bytes\n",s.st_size);
        printf("Block_Size : %d\n",s.st_blksize);
        printf("number of  blocks : %d\n",s.st_blocks);
        printf("_____________\n");
      }
      else
      {
        printf("can not display file details\n");
      }
    }
  }
closedir(dr);
}

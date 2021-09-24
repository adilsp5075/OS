#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
void *shared_memory;
char buff[100];
int shmid=shmget((key_t)500,1024,0666);
printf("Key of shared memmory is %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("Process is attached at %p\n\n",shared_memory);
printf("%sMessage recieved successfully!!",(char *)shared_memory);
}
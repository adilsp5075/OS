#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
void *shared_memmory;
char buff[100];
int shmid=shmget((key_t)500,1024,0666|IPC_CREAT);
printf("key of shared memmory is %d\n",shmid);
shared_memmory=shmat(shmid,NULL,0);
printf("Process attached at %p\n\n",shared_memmory);
printf("Type something.....!!\n");
read(0,buff,100);
strcpy(shared_memmory,buff);
printf("Message send!!\n\n");
}

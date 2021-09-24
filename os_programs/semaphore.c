#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int s=1;
void wait()
{
while(s<=0);
s--;
}
void signal()
{
s++;
}
void *p1()
{
printf("executing entry section of process 1\n");
wait();
printf("executing critical section of process 1\n");
sleep(4);
signal();
printf("executing remaining section of process 1\n");
}
void *p2()
{
printf("executing entry section of process 2\n");
wait();
printf("executing critical section of process 2\n");
sleep(4);
signal();
printf("executing remaining section of process 2\n");
}
int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,p1,NULL);
pthread_create(&t2,NULL,p2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
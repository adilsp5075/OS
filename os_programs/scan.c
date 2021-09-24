#include<stdio.h>
void main()
{
int n,i,j,k=0,seek_time=0,cp,limit;
printf("Enter the number of requests\n");
scanf("%d",&n);
int data[n][2];
for(i=0;i<n;++i)
{
printf("Enter the location of data %d\n",i);
scanf("%d",&data[i][0]);
data[i][1]=0;
}
printf("enter the curent head position\n");
scanf("%d",&cp);
printf("enter the limit of disk \n");
scanf("%d",&limit);
while(k<n && cp<=limit)
{
for(i=0;i<n;++i)
{
if(cp==data[i][0]&&data[i][1]==0)
{
printf("executing request at position %d\n",data[i][0]);
k++;
data[i][1]=1;
}
}
cp++;
seek_time++;
}
if(cp>limit && k<n)
{
seek_time--;
cp--;
while(k<n)
{
for(i=0;i<n;++i)
{
if(cp==data[i][0]&&data[i][1]==0)
{
printf("executing request at position %d\n",data[i][0]);
k++;
data[i][1]=1;
}
}
cp--;
seek_time++;
}
}
printf("total seek time is : %d\n",(seek_time-1));
}
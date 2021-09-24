#include<stdio.h>
void main()
{
int n,i,j,seek_time=0,cp;
printf("Enter the number of requests\n");
scanf("%d",&n);
int data[n];
for(i=0;i<n;++i)
{
printf("Enter the location of data %d\n",i);
scanf("%d",&data[i]);
}
printf("enter the curentn head position\n");
scanf("%d",&cp);
for(i=0;i<n;++i)
{
printf("executing request at position %d\n",data[i]);
j=cp-data[i];
if(j<0)
{
j=j*-1;
}
cp=data[i];
seek_time=seek_time+j;
}
printf("total seek time is : %d\n",seek_time);
}
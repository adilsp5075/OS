#include<stdio.h>
void main()
{
int blocks,process,b_Arr[10],p_Arr[10];
printf("enter number of memmory blocks\n");
scanf("%d",&blocks);
printf("enter size of each blocks\n");
for(int i=0;i<blocks;++i)
scanf("%d",&b_Arr[i]);
printf("enter number of processes\n");
scanf("%d",&process);
printf("enter size of each processes\n");
for(int i=0;i<process;++i)
scanf("%d",&p_Arr[i]);
int flag[process],allocation[process];
for(int i=0;i<process;++i)
{
flag[i]=0;
allocation[i]=-1;
}
int min;
for(int i=0;i<process;++i)
for(int j=0;j<blocks;++j)
{
if(flag[i]==0 && b_Arr[j]>=p_Arr[i])
{
min=b_Arr[j];
allocation[i]=j;
for(int k=j+1;k<blocks;++k)
{
if(b_Arr[k]>=p_Arr[i] && b_Arr[k]<min)
{
min=b_Arr[k];
allocation[i]=k;
j=k;
}
}
flag[i]=1;
b_Arr[j]-=p_Arr[i];
break;
}
}
printf("Process no Process size Block no\n");
for(int i=0;i<process;++i)
{
printf("%d\t\t%d\t\t",i+1,p_Arr[i]);
if(flag[i]==1)
printf("%d\n",allocation[i]+1);
else
printf("not allocated\n");
}}
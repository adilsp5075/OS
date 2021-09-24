#include<stdio.h>
void main()
{
int n,first,small,k=0,systime=0,l=0;
float rtsum=0,ctsum=0,ttsum=0,wtsum=0;
printf("enter the number of processes\n");
scanf("%d",&n);
int arr[n][4];
struct performance_parameters
{
int rt;
int ct;
int tt;
int wt;
};
struct performance_parameters pp[n];
for(int i=0;i<n;i++)
{
printf("enter details of process %d\n",(i+1));
printf("enter burst time\n");
scanf("%d",&arr[i][0]);
printf("enter arrival time\n");
scanf("%d",&arr[i][1]);
arr[i][2]=1;
printf("enter priority\n");
scanf("%d",&arr[i][3]);
}
first=0;
for(int i=0;i<n;++i)
{
small=100;
for(int j=0;j<n;++j)
{
if ((arr[j][2] != 0)&&(arr[j][1]<=systime))
{
if(arr[j][3]<small)
{
small=arr[j][3];
first=j;
}
l=1;
}
}
if(l==1)
{
if(k==0)
{
k=1;
systime=arr[first][1];
}
arr[first][2]=0;
//printf("executing process %d\n",(first+1));
pp[first].rt=systime-arr[first][1];
pp[first].ct=systime+arr[first][0];
pp[first].tt=pp[first].ct-arr[first][1];
pp[first].wt=systime-arr[first][1];
systime=systime+arr[first][0];
l=0;
}
else
{
systime=systime+1;
i--;
}
}
printf("PID \t RESPONSE TIME \t COMPLETION TIME \t TURNAROUND TIME \t WAITINGTIME\n");
printf("___ \t _____________ \t _______________ \t _______________ \t____________\n");
for(int i=0;i<n;++i)
{
printf("P%d \t\t %d \t\t %d \t\t\t %d \t\t\t %d",i+1,pp[i].rt,pp[i].ct,pp[i].tt,pp[i].wt);
printf("\n");
rtsum=rtsum+pp[i].rt;
ctsum=ctsum+pp[i].ct;
ttsum=ttsum+pp[i].tt;
wtsum=wtsum+pp[i].wt;
}
printf("\nAVERAGE RESPONSE TIME : %f\n",(rtsum/n));
printf("AVERAGE COMPLETION TIME : %f\n",(ctsum/n));
printf("AVERAGE TURNAROUND TIME : %f\n",(ttsum/n));
printf("AVERAGE WAITING TIME : %f\n",(wtsum/n));
}
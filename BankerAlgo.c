#include<stdio.h>
void main()
{
int k,l,flag=0,a=50,finish[10],allocated[100][100],available[10],max[100]
[100],n,m,i,j,count=0,need[100][100];
printf("enter the no. of processes\n");
scanf("%d",&m);
printf("enter no of resources\n");
scanf("%d",&n);
printf("enter allocation matrix\n");
for( i=0;i<m;i++){
printf("enter resources for process %d\n",i);
for( j=0;j<n;j++)
{
scanf("%d",&allocated[i][j]);
}}
printf("enter the max matrix\n");
for( i=0;i<m;i++){
printf("enter resources for process %d\n",i);
for( j=0;j<n;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("enter the available resources\n");
for( i=0;i<n;i++)
{
printf("enter the available resources for resourse %d",i);
scanf("%d",&available[i]);
}
printf("calculating need matrix..../n");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
need[i][j]=max[i][j]-allocated[i][j];
printf("need matrix\n\n");
for(i=0;i<m;i++)
{printf("process %d\n",i);
for(j=0;j<n;j++)
{
printf("%d",need[i][j]);
}
}
for(i=0;i<m;i++)
finish[i]=0;
while(a>0)
{a--;
for(i=0;i<m;i++)
{count=0;
if(finish[i]==0)
{
for(j=0;j<n;j++)
{
if(need[i][j]<=available[j])
{
count++;
}
}
if(count==n)
{
finish[i]=1;
for(l=0;l<n;l++)
available[l]+=allocated[i][l];
}
}
}
}
printf("\n\n\n");
for(i=0;i<n;i++)
printf("%d\n",available[i]);
printf("\n\n\n\n");
for(i=0;i<m;i++)
{
if(finish[i]==0)
flag=1;
}
if(flag==1)
printf("deadlocked");
else
printf("safe state");
}

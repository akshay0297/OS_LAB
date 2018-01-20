#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,check,j,n,m,job[100];
int a[100];
printf("Enter the no of partitions\n");
scanf("%d",&n);
int parts[n];
//entering partition sizes....
printf("Enter the partition sizes\n");
for(i=0;i<n;i++)
{
scanf("%d",&parts[i]);
}
printf("Enter the no of jobs\n");
scanf("%d",&m);
if(m>n)
{
printf("jobs are more than partitions\n");
exit(0);
}
printf("Enter the sizes of Jobs\n");
for(i=0;i<m;i++)
{
scanf("%d",&job[i]);
}
for(i=0;i<n;i++)
{
printf("partition %d : %d \n\n",i,parts[i]);
a[i]=99;
}
for(i=0;i<m;i++)
{
printf("job %d :: %d\n\n",i,job[i]);
}
for(i=0;i<m;i++)
{check=1;
for(j=0;j<n;j++)
{
if(parts[j]>=job[i])
{
parts[j]=parts[j]-job[i];
a[j]=i;
printf("partition %d is mapped to process %d \n",j,a[j]);
check=0;
break;
}}
if(check==1)//check if the process is allocated
{
printf("%d job is not allocated\n\n\n",i);
}
}
}

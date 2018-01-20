#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,check,j,temp,n,m,job[100],num[100];
printf("Enter the no of partitions\n");
scanf("%d",&n);
int parts[n];
//entering partition sizes....
printf("Enter the partition sizes\n");
for(i=0;i<n;i++)
{
num[i]=i;
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
for(i=0;i<n;i++){
printf("partition %d : %d \n\n",i,parts[i]);
}
for(i=0;i<m;i++)
{
printf("job %d :: %d\n\n",i,job[i]);
}
for(i=0;i<n;i++)//sorting in increasing order
{
for(j=0;j<n;j++)
{
if(parts[j]>parts[j+1])
{
temp=parts[j+1];
parts[j+1]=parts[j];
parts[j]=temp;
temp=num[j+1];
num[j+1]=num[j];
num[j]=temp;
}
}
}
for(i=0;i<n;i++)
{
printf("num %d\n\n",num[i]);
}
for(i=0;i<n;i++)
printf("part %d\n\n",parts[i]);
///allocating
for(i=0;i<m;i++)
{
check=1;
for(j=0;j<n;j++)
{
if(parts[j]>=job[i])
{
parts[j]=parts[j]-job[i];
printf("partition %d is mapped to process %d \n",num[j],i);
check=0;
break;
}
}
if(check==1)//check if process is allocated
{
printf("%d job is not allocated\n\n\n",i);}
}
}

#include<stdio.h>
#include<stdlib.h>
void main()
{
int start,total,n,i,largest,least,j,k,temp,diff;
int input[50];
printf("enter the no\n ");
scanf("%d",&n);
printf("enter the input\n");
for(i=0;i<n;i++)
{
scanf("%d",&input[i]);
}
printf("enter the start point\n");
scanf("%d",&start);
largest=input[0];
least=input[0];
//sorting
printf("\n");

for(i=0;i<n-1;i++)
for(j=0;j<(n-i-1);j++)
{
	if(input[j]>input[j+1])
	{
		temp=input[j];
		input[j]=input[j+1];
		input[j+1]=temp;
	}
}





for(i=0;i<n;i++)
{
if(input[i]<=start&&start<input[i+1])
{
k=i;
}
}



if(start<100)
{

total=total+(start-input[0]);
total=total+(input[n-1]-input[k+1]);
}
else
{

total=total+(input[n-1]-start);
total=total+input[k-1];
}
printf("Total tracks covered=%d\n",total);
}

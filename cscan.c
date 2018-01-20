#include<stdio.h>
#include<stdlib.h>
void main()
{
int start,total,n,i,largest,least,j,k,temp;
int input[50];
printf("Enter the no: \n");
scanf("%d",&n);
printf("enter the input \n");
for(i=0;i<n;i++)
{
scanf("%d",&input[i]);
}
printf("enter the start point\n\n");
scanf("%d",&start);
largest=input[0];
least=input[0];
for(i=0;i<n;i++)
for(j=0;j<n;j++)
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
total=total+start;
total=total+(199-input[k+1]);
}
else
{
total=total+(199-start);
total=total+input[k-1];
}
printf("Total tracks recorded=%d\n\n",total);
}

#include<stdio.h>
#include<stdlib.h>
void main()
{
int start,total,n,i,largest,least,j,temp;
int input[50],input1[50];
printf("enter the no:\n");
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


if(start<100)
{
total=total+start;
for(i=0;i<n;i++)
{
if(largest<input[i])
{
largest=input[i];
}
}
total=total+largest;
}
else
{
total=total+(199-start);
for(i=0;i<n;i++)
{
if(least>input[i])
{
least=input[i];
}
}
total=total+(199-least);
//total=total-(2*(199-input1[n-1]));

}
printf("Total tracks travelled=%d\n",total);
for(i=0;i<n;i++)
{
input1[i]=input[i];
}


for(i=0;i<(n-1);i++)
for(j=0;j<(n-i-1);j++)
{
	if(input1[j]>input1[j+1])
	{
		temp=input1[j];
		input1[j]=input1[j+1];
		input1[j+1]=temp;
	}
}
printf("input1:\n\n");
for(j=0;j<n;j++)
printf("%d\t",input1[j]);
total=total-(2*input1[0]);
printf("Total tracks travelled=%d\n",total);
}

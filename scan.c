#include<stdio.h>
#include<stdlib.h>
void main()
{
int start,total=0,n,i,largest,least;
int input[50];
printf("Enter the no:");
scanf("%d",&n);
printf("Enter the input:\n");
for(i=0;i<n;i++)
{
scanf("%d",&input[i]);
}
printf("Enter the start point:\n");
scanf("%d",&start);
largest=input[0];
least=input[0];

if(start<100)
{//printf("total: %d",total);
//printf("start: %d",start);
total=total+start;
//printf("total: %d",total);
for(i=0;i<n;i++)
{
if(largest<input[i])
{
largest=input[i];
//printf("Largest: %d",largest);
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
}
printf("Total tracks recorded=%d\n\n",total);
}

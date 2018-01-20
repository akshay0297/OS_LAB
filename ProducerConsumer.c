#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define cap 5

sem_t full , empty;
pthread_mutex_t pmutex , cmutex  , mutex;
pthread_t tidp[20] ,tidc[20];
int buffer[cap];
int pitem  , citem ;
int ct ;
void inst(int item)
{
 buffer[ct++] = item;
}
int rem()
{
    return(buffer[--ct]);
}
void initialize()
{
    pthread_mutex_init(&mutex,NULL);
	pthread_mutex_init(&pmutex,NULL);
	pthread_mutex_init(&cmutex,NULL);
	sem_init(&full,1,0);
	sem_init(&empty,1,cap);
	ct=0;
}
void *producer()
{
    int item;
    sem_wait(&empty);
    item = rand()%5;
    pthread_mutex_lock(&mutex);
    printf("Producer is Producing an item :");
    inst(item);
    printf("%d \n" , item);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}
void *consumer()
{
    int item;
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    printf("Consumer is taking  an item : ");
    item = rem();
    printf("%d \n " ,item);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main()
{
  int n , m , i;
  initialize();
  printf("Enter the number of therads of producer : ");
  scanf("%d" , &n);
  printf("\n Enter the number of therads of consumer : ");
  scanf("%d" , &m);
  for(i = 0 ; i<n ; i++)
  {
    pthread_create(&tidp[i] , NULL , producer , NULL);
  }
  for(i = 0 ; i<m ; i++)
  {
    pthread_create(&tidc[i] , NULL , consumer , NULL);
  }
  for(i=0;i<n;i++)
		pthread_join(tidp[i],NULL);
  for(i=0;i<m;i++)
		pthread_join(tidc[i],NULL);
    exit(0);
}


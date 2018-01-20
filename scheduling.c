#include<stdio.h>
int main()
{
    int  a[10] , p[10] , bt[10] , tat[10] , wt[10] , ct[10] , pr[10];
    int n;
    printf("Ente the number of processes :");
    scanf("%d" , &n);
    printf("Enter their respective process number :");
    int j , i;
    for(j=0 ; j<n ; j++)
    {
    scanf("%d" , &pr[j]);
    }
    printf("Enter their respective arrival time :");
    for(i=0 ; i<n ; i++)
    {
    scanf("%d" , &a[i]);
    }
    printf("Enter their respective burst time :");
    for(i=0 ; i<n ; i++)
    {
    scanf("%d" , &bt[i]);
    }
    printf("Enter their respective  priorities :");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d" , &p[i]);
    }
    printf("1.FCFS \t 2.SRJF \t 3.PRIORITY NON PREEMPTIVE \t 4.ROUND ROBIN \n");
    int c;
    scanf("%d" , &c);
    switch(c)
    {
        case 1: for(i=0 ; i<n ; i++)
                {
                    for(j=i+1 ; j<n ; j++)
                    {
                        if(a[i] > a[j])
                        {
                            int temp = a[i];
                            a[i] =a[j];
                            a[j] = temp;
                            int t = bt[i];
                            bt[i] =bt[j];
                            bt[j] = t;
                            int te = p[i];
                            p[i] =p[j];
                            p[j] = te;
                            int tem = pr[i];
                            pr[i] =a[j];
                            pr[j] = tem;
                        }
                    }
                }
                int st=0 ;
                for(i=0 ; i<n ;i++)
                {
                    ct[i] = bt[i] + st;
                    st=ct[i];
                }
                for(i=0 ; i<n ; i++)
                {
                    tat[i] = ct[i] - a[i];
                    wt[i] = tat[i] - bt[i];
                }

    printf(" PNO \t AT \t BT \t CT \t TAT \t WT \n");
        for(i=0 ; i<n ; i++)
        {
            printf("%d \t %d \t %d \t %d \t %d \t %d \t \n" , pr[i] , a[i] , bt[i] , ct[i] , tat[i] , wt[i]);
        }
        printf("Gantt Chart : ");
        for(i=0 ; i<n ; i++)
        {
           printf("%d \t" , ct[i]);
        }
    case 3: for(i=0 ; i<n ; i++)
                {
                    for(j=i+1 ; j<n ; j++)
                    {
                        if(p[i] > p[j])
                        {
                            int temp = a[i];
                            a[i] =a[j];
                            a[j] = temp;
                            int t = bt[i];
                            bt[i] =bt[j];
                            bt[j] = t;
                            int te = p[i];
                            p[i] =p[j];
                            p[j] = te;
                            int tem = pr[i];
                            pr[i] =a[j];
                            pr[j] = tem;
                        }
                    }
                }
                for(i =0 ; i<n-1 ; i++)
                {
                    if(p[i] == p[i+1] && a[i]>a[i+1])
                    {

                            int temp = a[i];
                            a[i] =a[i+1];
                            a[i+1] = temp;
                            int t = bt[i];
                            bt[i] =bt[i+1];
                            bt[i+1] = t;
                            int te = p[i];
                            p[i] =p[i+1];
                            p[i+1] = te;
                            int tem = pr[i];
                            pr[i] =pr[i+1];
                            pr[i+1] = tem;
                    }
                }
                st=0 ;
                for(i=0 ; i<n ;i++)
                {
                    ct[i] = bt[i] + st;
                    st=ct[i];
                }
                for(i=0 ; i<n ; i++)
                {
                    tat[i] = ct[i] - a[i];
                    wt[i] = tat[i] - bt[i];
                }

    printf(" PNO \t AT \t BT \t PRIO \t CT \t TAT \t WT \n");
        for(i=0 ; i<n ; i++)
        {
            printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t \n" , pr[i] , a[i] , bt[i] , p[i] , ct[i] , tat[i] , wt[i]);
        }
        printf("Gantt Chart : ");
        for(i=0 ; i<n ; i++)
        {
           printf("%d \t" , ct[i] );
        }
        printf("\n");
    }
    return 0;
}

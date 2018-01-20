#include<stdio.h>
#include <stdlib.h>

int main(){
	int arrival_time[50],burst_time[51],priority[50],process_id[50];
	int timeline[1000] , i , j , t;
	for(i = 0;i < 1000;i++)
		timeline[i] = -1;
	int max_no = 100;
	while(max_no > 50){	
		printf("\nEnter number of processes : ");
		scanf("%d",&max_no);
		if (max_no>50)
			printf("\nEnter number less than 50");
	}
	for(i = 0;i<max_no;i++){
		printf("\nEnter arrival time for process %d: ",i);
		scanf("%d",	&arrival_time[i]);
		printf("\nEnter burst time for process %d: ",i);
		scanf("%d", &burst_time[i]);	
		process_id[i]=i;
	}
	burst_time[max_no+1] = 9999;
	for(i = 0;i<max_no;i++){
		printf("\nAT[%d] : %d",process_id[i],arrival_time[i]);
		printf("\t BT[%d] : %d , \n",process_id[i],burst_time[i]);
	}
	for(i = 0;i<max_no;i++){
		for(j = i;j<max_no ; j++){
			int temp;
			if(arrival_time[i] > arrival_time[j]){
				temp = arrival_time[i];
				arrival_time[i] = arrival_time[j];
				arrival_time[j] = temp;			
				temp = burst_time[i];
				burst_time[i] = burst_time[j];
				burst_time[j] = temp;
				temp = priority[i];
				priority[i] = priority[j];
				priority[j] = temp;			
				temp = process_id[i];
				process_id[i] = process_id[j];
				process_id[j] = temp;
			}			
		}	
	}
	int time=0;
	for(i = 0;i<max_no;i++)
		time+=burst_time[i];
	printf("\nTotal Time : %d",time);
	printf("Gantt Chart :: \n");
	for(t = 0;t<time;t++){
		int shortest_job=max_no+1;		
		for(i = 0;i<max_no;i++){
			if(arrival_time[i] <= t){
				if(burst_time[i] < burst_time[shortest_job] && burst_time[i]!=0)
					shortest_job = i;
			}		
		}
		burst_time[shortest_job]--;
		printf("P%d ",process_id[shortest_job]); 	
	}
	printf("\n");
	
	return 0;
}

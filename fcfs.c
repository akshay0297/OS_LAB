#include<stdio.h>
#include <stdlib.h>

int main(){
	int arrival_time[50],burst_time[50],process_id[50];
	int max_no = 100;
	while(max_no > 50){	
		printf("\nEnter number of processes : ");
		scanf("%d",&max_no);
		if (max_no>50)
			printf("\nEnter number less than 50");
	}
	for(int i = 0;i<max_no;i++){
		printf("\nEnter arrival time for process %d: ",i);
		scanf("%d",	&arrival_time[i]);
		printf("\nEnter burst time for process %d: ",i);
		scanf("%d", &burst_time[i]);	
		process_id[i]=i;
	}
	for(int i = 0;i<max_no;i++){
		printf("\nAT[%d] : %d",process_id[i],arrival_time[i]);
		printf("\nBT[%d] : %d",process_id[i],burst_time[i]);
	}
	for(int i = 0;i<max_no;i++){
		for(int j = i;j<max_no ; j++){
			int temp;
			if(arrival_time[i] > arrival_time[j]){
				temp = arrival_time[i];
				arrival_time[i] = arrival_time[j];
				arrival_time[j] = temp;			
				temp = burst_time[i];
				burst_time[i] = burst_time[j];
				burst_time[j] = temp;			
				temp = process_id[i];
				process_id[i] = process_id[j];
				process_id[j] = temp;
			}		
		}	
	}
	printf("\n\nAfter sorting :\n");
	for(int i = 0;i<max_no;i++){
		printf("\nAT[%d] : %d",process_id[i],arrival_time[i]);
		printf("\nBT[%d] : %d",process_id[i],burst_time[i]);
	}
	printf("\n\nGantt chart : ");
	for(int i = 0;i<max_no;i++){
		for(int j = 0;j<burst_time[i];j++){
			printf("P%d ",process_id[i]);		
		}	
		printf("| ");
	}
	printf("\n");
	return 0;
}

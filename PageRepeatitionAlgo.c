#include<stdio.h>
int main() {
int pagefault, pagestring[100], maxpages;
int choice;
int buffersize;
int i, j, k, present;
int fifo[20], fifotop = 0;
int optimal[20], optimaltop = 0;
int farthest[20], max, maxIndex, futex;
printf("Choose buffersize: ");
scanf("%d", &buffersize);
printf("\nMenu\n1. FIFO\n2. Optimal\n");
printf("\nEnter choice: ");
scanf("%d", &choice);
if(choice == 1) {
for(i=0; i<buffersize; i++)
fifo[i] = -1;
pagefault = 0;
printf("\nEnter the number of pages: ");
scanf("%d", &maxpages);
printf("Enter page numbers separated by a space: ");
for(i=0; i<maxpages; i++)
scanf("%d", &pagestring[i]);
for(j=0; j<maxpages; j++) {
present = 0;
for(i=0; i<buffersize; i++)
if(pagestring[j] == fifo[i]) {present = 1;
break;
}
printf("For page number %d:", pagestring[j]);
if(present == 0) {
printf("\nPage Fault!\n");
pagefault++;
fifo[fifotop] = pagestring[j];
fifotop = (fifotop + 1) % buffersize;
for(i=0; i<buffersize; i++)
if(fifo[i] != -1)
printf(" %d ", fifo[i]);
}
else if(present == 1)
printf("\nPage already present.No page fault");
}
printf("\nTotal page faults: %d\n\n", pagefault);
}
else if(choice == 2) {
for(i=0; i<buffersize; i++)
optimal[i] = -1;
pagefault = 0;
printf("\nEnter the number of pages: ");
scanf("%d", &maxpages);
printf("Enter page numbers separated by a space: ");
for(i=0; i<maxpages; i++)
scanf("%d", &pagestring[i]);
for(k=0; k<maxpages; k++) {
present = 0;
for(i=0; i<buffersize; i++)
if(pagestring[k] == optimal[i]) {
present = 1;
break;
}
printf("For page number %d:", pagestring[k]);
if(present == 0) {
pagefault++;max = -1;
for(i=0; i<buffersize; i++) {
futex = 0;
for(j=k+1; j<maxpages; j++)
if(optimal[i] == pagestring[j]) {
futex = 1;
farthest[i] = j;
if(farthest[i] >= max) {
max = farthest[i];
maxIndex = i;
}
break;
}
if(futex == 0) {
maxIndex = i;
break;
}
}
printf("\nPage Fault!\n");
optimal[maxIndex] = pagestring[k];
for(i=0; i<buffersize; i++)
if(optimal[i] != -1)
printf(" %d ", optimal[i]);
}
else if(present == 1)
printf("\nPage already present. No page fault");
}
printf("\nTotal page faults: %d\n\n", pagefault);
}
}

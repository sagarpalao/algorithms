/**
Program to analyze time complexity of Quick Sort
*/
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define n 5
int a[n];
void read_array();
void print_array();
void quick_sort(int,int);
int partition(int,int);
void main(){
int i;
clock_t start,end;
double duration;
clrscr();
printf("ENTER 5 ELEMENTS (UNSORTED): ");
read_array();
start=clock();
quick_sort(0,n-1);
end=clock();
duration=(double)((end-start)/CLOCKS_PER_SEC);
printf("\n\n\nSORTED ARRAY:\n");
print_array();
printf("\nTIME DURATION: %f",duration);
getch();
}
void read_array(){
int i;
for(i=0;i<n;i++){
printf("\n\tEnter element %d: ",(i+1));
scanf("%d",&a[i]);
}
}
void print_array(){
int i;
for(i=0;i<n;i++){
printf("\t%d",a[i]);
}
}
void quick_sort(int l,int u){
int index;
if(l<u){
index=partition(l,u);
quick_sort(l,index-1);
quick_sort(index+1,u);
}
}
int partition(int l,int u){
int pivot=a[l];
int rindex,lindex,temp,k;
int pivot_index=l;
int flagl=1;
int flagr=1;
while(flagl==1||flagr==1){
for(k=u;k>=pivot_index;k--){
if(a[k]<pivot){
flagr=1;
rindex=k;
break;
}
else{
flagr=0;
}
}
if(flagr==1){
temp=a[rindex];
a[rindex]=a[pivot_index];
a[pivot_index]=temp;
pivot=a[pivot_index];
}
for(k=l;k<=pivot_index;k++){
if(a[k]>pivot){
flagl=1;
lindex=k;
break;
}
else{
flagl=0;
}
}
if(flagl==1){
temp=a[lindex];
a[lindex]=a[pivot_index];
a[pivot_index]=temp;
pivot=a[pivot_index];
}
}
return pivot_index;
}
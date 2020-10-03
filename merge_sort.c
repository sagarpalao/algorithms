/**
Program to analyze time complexity of Merge Sort
*/
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define n 5
int a[n];
void read_array();
void print_array();
void merge_sort(int,int);
void merge(int,int,int,int);
void merge(int m,int l,int p,int q){
int c[5];
int i=m;
int j=p;
int k=0;
while(i<=l&&j<=q){
if(a[i]<a[j]){
c[k]=a[i];
i++;
k++;
}
else{
c[k]=a[j];
j++;
k++;
}
}
while(i<=l){
c[k]=a[i];
k++;
i++;
}
while(j<=q){
c[k]=a[j];
k++;
j++;
}
for(i=m,j=0;i<=q;i++,j++){
a[i]=c[j];
}
}
void main(){
int i;
clock_t start,end;
double duration;
clrscr();
printf("ENTER 5 ELEMENTS (UNSORTED): ");
read_array();
start=clock();
merge_sort(0,n-1);
end=clock();
duration=(double)(end-start)/CLOCKS_PER_SEC;
printf("\n\n\nSORTED ARRAY:\n");
print_array();
printf("\nSORTING TIME : %f",duration);
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
void merge_sort(int i,int j){
int k;
if(i<j){
k=(i+j)/2;
merge_sort(i,k);
merge_sort((k+1),j);
merge(i,k,(k+1),j);
}
}
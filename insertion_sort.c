/**
	Program to analyse Insertion Sort
*/

#include<stdio.h>
#include<conio.h>
#include<time.h>
#define n 10
int arr[n];

void accept();
void print_array();
void insertion_sort();

void main(){

	clock_t start,end;
	double difference;
	clrscr();

	accept();

	start=clock();
	insertion_sort();
	end=clock();

	difference=(double)(end-start)/CLOCKS_PER_SEC;

	print_array();
	printf("\nTIME COMPUTATION: %f",difference);

	getch();
}

void accept(){
	int i;
	printf("\nEnter 10 elements: ");
	for(i=0;i<n;i++){
		printf("\nEnter element [%d]: ",(i+1));
		scanf("%d",&arr[i]);
	}
}
void print_array(){
	int i;
	for(i=0;i<n;i++){
		printf("\t%d",arr[i]);
	}
}
void insertion_sort(){
	int i,j;
	int key;
	for(i=1;i<n;i++){
		key=arr[i];
		for(j=i-1;j>=0&&arr[j]>key;j--){
			arr[j+1]=arr[j];
		}
		arr[j+1]=key;
	}

}



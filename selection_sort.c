#include<stdio.h>
#include<conio.h>
#include<time.h>
#define n 10
int arr[n];

void accept();
void print_array();
void selection_sort();

void main(){

	clock_t start,end;
	double difference;
	clrscr();

	accept();

	start=clock();
	selection_sort();
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
void selection_sort(){
	int small_index;
	int temp,i,j;

	for(i=0;i<n;i++){
		small_index=i;

		for(j=i+1;j<n;j++){
			if(arr[small_index]>arr[j]){
				small_index=j;
			}
		}

		if(i!=small_index){
			temp=arr[small_index];
			arr[small_index]=arr[i];
			arr[i]=temp;
		}
	}
}

#include<stdio.h>
#include<conio.h>
#include<time.h>
#define n 5

int arr[n];

void MinMax(int start,int end,int *min,int *max){

	int min1,max1,mid;

	if(start==end){
		(*min)=arr[start];
		(*max)=arr[start];
	}
	else if(start==end-1){
		if(arr[start]>arr[end]){
			(*max)=arr[start];
			(*min)=arr[end];
		}
		else{
			(*max)=arr[end];
			(*min)=arr[start];
		}
	}
	else{
		mid=(start+end)/2;
		MinMax(start,mid,min,max);
		MinMax(mid+1,end,&min1,&max1);

		if((*min)>(min1)){
			(*min)=(min1);
		}

		if((*max)<(max1)){
			(*max)=(max1);
		}
	}
}

void main(){

	int min,max;
	int i;

	clock_t start,end;
	double duration;

	clrscr();

	printf("\nEnter 5 element: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	start=clock();
	MinMax(0,n-1,&min,&max);
	end=clock();

	duration=((double)(end-start)/CLOCKS_PER_SEC);

	printf("\nMinimum: %d",min);
	printf("\nMaximum: %d",max);
	printf("\nComputation Time: %f",duration);

	getch();
}

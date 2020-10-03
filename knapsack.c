/**
	Program to implement Knapsack problem
*/
#include<stdio.h>
#include<conio.h>
#define n 4

int obj[n];
float a[3][n];
float sack[n];
float m;

void accept();
void fillKnapsack();
void sort();

void main(){
	clrscr();
	accept();
	sort();
	fillKnapsack();
	getch();
}

void accept(){
	int i;
	for(i=0;i<n;i++){
		obj[i]=i+1;
	}
	printf("Enter weight for each object: ");
	for(i=0;i<n;i++){
		printf("\nObject %d: ",obj[i]);
		scanf("%f",&a[0][i]);
	}
	printf("\n\nEnter profit for each object: ");
	for(i=0;i<n;i++){
		printf("\nObject %d: ",obj[i]);
		scanf("%f",&a[1][i]);
	}
	for(i=0;i<n;i++){
		a[2][i]=a[1][i]/a[0][i];
	}
	printf("\n\nEnter capacity: ");
	scanf("%f",&m);
}

void sort(){
	int i,j,x,t;
	float tmp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(a[2][j]<a[2][j+1]){
				for(x=0;x<3;x++){
					tmp=a[x][j];
					a[x][j]=a[x][j+1];
					a[x][j+1]=tmp;
				}
				t=obj[j];
				obj[j]=obj[j+1];
				obj[j+1]=t;
			}
		}
	}
}

void fillKnapsack(){
	float profit;
	int i;
	float capacity;
	capacity=m;
	profit=0;
	for(i=0;i<n;i++){
		if(a[0][i]<=capacity){
			sack[i]=1.0;
			capacity=capacity-a[0][i];
			profit=profit+a[1][i];
		}
		else{
			break;
		}
	}
	if(i<n){
		sack[i]=capacity/a[0][i];
		profit=profit+sack[i]*a[1][i];
	}
	for(i=0;i<n;i++){
		printf("\n\n%d",obj[i]);
		printf("\t%f",sack[i]);
	}
	printf("\n\nProfit: %f",profit);
}

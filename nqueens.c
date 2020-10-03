/**
	@AIM: Program to implement n-Queens Problem
	@Author: Roll No.: 73,77
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>

int n;
int x[20];

void nqueen(int);
int place(int,int);
void display();

void main(){

	int i;
	clrscr();
	printf("\nEnter no. of quuens: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		x[i]=0;
	}
	nqueen(0);
	getch();
}

int place(int k,int i){
	int j;
	for(j=0;j<k;j++){
		if(x[j]==i || abs(j-k)==abs(x[j]-i)){
			return 0;
		}
	}
	return 1;
}

void nqueen(int k){

	int i,m;
	for(i=0;i<n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n-1){
				printf("\nSolution Set:\n ");
				for(m=0;m<n;m++){
					printf("\t%d",x[m]);
				}
				printf("\nPosition table for queens:\n");
				display();
				getch();
				exit();
			}
			else{
				nqueen(k+1);
			}
		}
	}
}
void display(){

	int i,j;
	char q[20][20];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			q[i][j]='-';
		}
	}
	for(i=0;i<n;i++){
		q[i][x[i]]='Q';
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%c ",q[i][j]);
		}
		printf("\n");
	}
}

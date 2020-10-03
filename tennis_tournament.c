/**
 @Aim: To Implement Tennis tournament Problem
 @Author: 73,77,79.
*/ 

#include<stdio.h>
#include<conio.h>

int t[20][20];

void tennis(int,int,int,int);
void conquer(int,int,int,int);
void display(int);

void main(){

	int n;

	clrscr();
	printf("Enter no. of palyers: ");
	scanf("%d",&n);

	tennis(0,n-1,0,n-2);
	display(n);
	getch();
}

void tennis(int rl,int ru,int cl,int cu){
	int x,y;

	if(ru-rl==1){
		t[rl][cl]=ru;
		t[ru][cl]=rl;
	}
	else{
		x=(rl+ru)/2;
		y=(cl+cu)/2;
		tennis(rl,x,cl,y-1);
		tennis(x+1,ru,cl,y-1);
		conquer(rl,ru,y,cu);
	}
}

void conquer(int rl,int ru,int cl,int cu){

	int off,k,i,j;

	off=0;

	for(i=cl;i<=cu;i++){
		k=(rl+ru)/2+1+off;
		for(j=rl;j<=(rl+ru)/2;j++){
			t[j][i]=k;
			k++;
			if(k>ru){
				k=(rl+ru)/2+1;
			}
		}
		off++;
	}

	off=0;

	for(i=cl;i<=cu;i++){
		k=rl+off;
		for(j=(rl+ru)/2+1;j<=ru;j++){
			t[j][i]=k;
			k++;
			if(k>(rl+ru)/2){
				k=rl;
			}
		}
		off++;
	}
}

void display(int n){
	int i,j;
	for(i=0;i<n;i++){
		printf("\n%3d: ",i);
		for(j=0;j<n-1;j++){
			printf("%3d",t[i][j]);
		}
	}
}

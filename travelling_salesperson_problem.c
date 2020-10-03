/**
	@Aim: Program to implement Travelling salesperson problem (Branch & Bound)
	@Author: Roll No. 73, 77
*/
#include<stdio.h>
#include<conio.h>
#define n 5

int t[n][n];
int x[n+1];

void tsp();
int reduce(int m[n][n]);
void disp(int b[n][n]);
int branch(int r[n][n],int b[n][n],int s,int d,int c);

void main(){
	int i,j;
	clrscr();
	printf("Enter adjacency cost matrix 5*5:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&t[i][j]);
		}
	}
	x[0]=0;
	x[n]=0;
	tsp();
	getch();
}

int reduce(int m[n][n]){
	int i,j,k,cost,min;

	cost=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(m[i][j]==0){
				break;
			}
		}
		if(j==n){
			for(k=0;k<n;k++){
				if(m[i][k]!=1000){
					break;
				}
			}
			if(k!=n){
				min=m[i][0];
				for(k=0;k<n;k++){
					if(min>m[i][k]){
						min=m[i][k];
					}
				}
				cost=cost+min;
				for(k=0;k<n;k++){
					if(m[i][k]!=1000){
						m[i][k]=m[i][k]-min;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(m[j][i]==0){
				break;
			}
		}
		if(j==n){
			for(k=0;k<n;k++){
				if(m[k][i]!=1000){
					break;
				}
			}
			if(k!=n){
				min=m[0][i];
				for(k=0;k<n;k++){
					if(min>m[k][i]){
						min=m[k][i];
					}
				}
				cost=cost+min;
				for(k=0;k<n;k++){
					if(m[k][i]!=1000){
						m[k][i]=m[k][i]-min;
					}
				}
			}
		}
	}
	return cost;
}

int branch(int r[n][n],int b[n][n],int s,int d,int c){

	int i,j,cost,c1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			b[i][j]=r[i][j];
		}
	}
	for(i=0;i<n;i++){
		b[s][i]=1000;
	}
	for(i=0;i<n;i++){
		b[i][d]=1000;
	}
	b[d][0]=1000;
	c1=reduce(b);
	cost=c+r[s][d]+c1;
	return cost;
}

void tsp(){

	int c,i,j,k,min,min_k,cost;
	int b[n][n];

	c=reduce(t);
	printf("\n\n");
	printf("%d",c);
	disp(t);
	printf("\n\n");

	for(i=n-1;i>=1;i--){
		min=1000;
		for(j=0;j<i;j++){
			for(k=0;k<n;k++){
				if(remains(k)){
					cost=branch(t,b,x[n-i-1],k,c);
					if(min>cost){
						min=cost;
						min_k=k;
					}
				}
			}
		}
		x[n-i]=min_k;
		c=branch(t,b,x[n-i-1],min_k,c);
		printf("%d",c);

		for(k=0;k<n;k++){
			for(j=0;j<n;j++){
				t[k][j]=b[k][j];
				printf("\t%d",t[k][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	printf("Path: ");
	for(k=0;k<n;k++){
			printf("\t%d",x[k]);
		}
	printf("\n\n");

	printf("COST: %d",cost);

}

int remains(int a){
	int i;
	for(i=0;i<n;i++){
		if(x[i]==a){
			break;
		}
	}
	if(i==n){
		return 1;
	}
	else{
		return 0;
	}
}

void disp(int b[n][n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("\t%d",b[i][j]);
		}
		printf("\n");
	}
}

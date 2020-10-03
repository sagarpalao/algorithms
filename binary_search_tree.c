/**
	@Aim: Program to implement Optimal Binary Search Tree
	@Author: Roll No. 73, 77
*/
#include<stdio.h>
#include<conio.h>

int n;
int w[20][20];
int c[20][20];
int r[20][20];
int p[20];
int q[20];

void accept();
void obst();

void main(){
	clrscr();
	accept();
	obst();
	getch();
}

void accept(){
	int i,j;
	printf("\nEnter no. of key elements: ");
	scanf("%d",&n);
	printf("\nEnter frequency of key elements:\n");
	for(i=1;i<=n;i++){
		printf("P%d: ",i);
		scanf("%d",&p[i]);
	}
	printf("\nEnter frequency of failure nodes:\n");
	for(j=0;j<=n;j++){
		printf("Q%d: ",j);
		scanf("%d",&q[j]);
	}
}

void obst(){
	int i,j,k,u,v,m,min,l;

	printf("\n\n\n");
	printf("\n\nOptimal search tree:\n\n\n");
	for(i=0;i<=n;i++){
		w[i][i]=q[i];
		c[i][i]=0;
		r[i][i]=0;
		printf("%2d | %2d | %2d\t",w[i][i],c[i][i],r[i][i]);
	}
	printf("\n");

	for(m=1;m<=n;m++){
		for(i=0;i<=n-m;i++){

			j=i+m;

			w[i][j]=p[j]+q[j]+w[i][j-1];

			min=1000;
			for(l=i+1;l<=j;l++){
				if(min>(c[i][l-1]+c[l][j])){
					min=c[i][l-1]+c[l][j];
					k=l;
				}
			}

			c[i][j]=c[i][k-1]+c[k][j]+w[i][j];

			r[i][j]=k;

			printf("%2d | %2d | %2d\t",w[i][j],c[i][j],r[i][j]);
		}
		printf("\n\n");
	}
}

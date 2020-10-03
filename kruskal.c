/**
	@AIM: To implement Kruskals Algorithm
	@AUTHOR: Roll No.: 73,77
*/
#include<stdio.h>
#include<conio.h>
#define n 4

int cost[n][n];
int edges[20][3];
int tree[n-1][2];
int parent[n];
int k;

void accept();
void kruskals();
void union_nodes();

void main(){
	clrscr();
	accept();
	kruskals();
	getch();
}

void accept(){
	int i,j;
	printf("Enter cost matrix for 4*4 graph:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
}

void kruskals(){

	int x,i,j,temp,mincost;

	x=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(cost[i][j]!=1000){
				edges[x][0]=i;
				edges[x][1]=j;
				edges[x][2]=cost[i][j];
				x++;
			}
		}
	}


	for(i=0;i<x-1;i++){
		for(j=0;j<x-1-i;j++){
			if(edges[j][2]>edges[j+1][2]){
				for(k=0;k<3;k++){
					temp=edges[j+1][k];
					edges[j+1][k]=edges[j][k];
					edges[j][k]=temp;
				}
			}
		}
	}

	for(i=0;i<n;i++){
		parent[i]=i;
	}

	k=0;
	mincost=0;

	for(i=0;i<x;i++){
		if(parent[edges[i][0]]!=parent[edges[i][1]]){
			tree[k][0]=edges[i][0];
			tree[k][1]=edges[i][1];
			mincost=mincost+edges[i][2];
			k++;
			union_nodes(tree[k][0],tree[k][1]);
		}
	}

	for(i=0;i<k;i++){
		printf("\nEdge: %d -> %d",tree[i][0],tree[i][1]);
	}

	printf("\nMinimum Cost: %d",mincost);
}

void union_nodes(int x,int y){
	int i,j;
	j=parent[x];
	parent[y]=j;
	for(i=0;i<k;i++){
		if(tree[i][0]==x||tree[i][0]==y){
			parent[tree[i][1]]=j;
		}
		if(tree[i][1]==x||tree[i][1]==y){
			parent[tree[i][0]]=j;
		}
	}
}

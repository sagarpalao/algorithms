/**
@AIM: PROGRAM TO IMPLEMENT PRIM’S ALGORITHM
@AUTHOR: ROLL NO.: 73, 77, 79
*/

#include<stdio.h>
#include<conio.h>

int cost[20][20];
int tree[20][2];
int nearr[20];
int n;

void prims();
void accept();
void print();

void main(){

	clrscr();
	accept();
	prims();
	print();

	getch();

}
void accept(){
	int i,j;

	printf("Enter no. of nodes:  ");
	scanf("%d",&n);
	printf("Enter adjancency matrix for %d * %d graph\n",n,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
}
void prims(){
	int i,j,temp,k,l,min;

	temp=cost[0][0];

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(temp>=cost[i][j]){
				temp=cost[i][j];
				k=i;
				l=j;
			}
		}
	}

	tree[0][0]=k;
	tree[0][1]=l;
	tree[0][2]=cost[k][l];

	for(i=0;i<n;i++){
		if(cost[i][k]<cost[i][l]){
			nearr[i]=k;
		}
		else{
			nearr[i]=l;
		}
	}
	nearr[k]=999;
	nearr[l]=999;

	for(i=1;i<n-1;i++){

		k=0;
		for(k=0;k<n;k++){
			if(nearr[k]!=999){
				min=cost[k][nearr[k]];
				break;
			}
		}

		j=0;

		for(k=0;k<n;k++){
			if(nearr[k]!=999){
				if(min>=cost[k][nearr[k]]){
					min=cost[k][nearr[k]];
					j=k;
				}
			}
		}

		tree[i][0]=j;
		tree[i][1]=nearr[j];
		tree[i][2]=cost[j][nearr[j]];
		nearr[j]=999;

		for(k=0;k<n;k++){
			if(nearr[k]!=999 && cost[k][nearr[k]]>cost[k][j]){
				nearr[k]=j;
			}
		}
	}
}

void print(){
	int i;
	int mincost=0;
	for(i=0;i<n-1;i++){
		printf("\n%d->%d\tweight:%d",tree[i][0],tree[i][1],cost[tree[i][0]][tree[i][1]]);
		mincost=mincost+cost[tree[i][0]][tree[i][1]];
	}
	printf("\nMinimum cost: %d",mincost);
}

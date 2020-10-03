/**
	@Aim: Program to implement Longest Common subsequence
	@Author: Roll No. 73, 77
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

char T[20];
char P[20];
char b[20][20];
int c[20][20];

void lcs();
void printS(int,int);

void main(){
	clrscr();
	printf("Enter text T: ");
	scanf("%s",&T);
	printf("\nEnter text P: ");
	scanf("%s",&P);
	lcs();
	getch();
}

void lcs(){
	int n,m;
	int i,j;

	n=strlen(P);
	m=strlen(T);

	for(i=n-1;i>=0;i--){
		P[i+1]=P[i];
	}
	P[n+1]='\0';
	for(i=m-1;i>=0;i--){
		T[i+1]=T[i];
	}
	T[m+1]='\0';

	for(i=0;i<=m;i++){
		c[0][i]=0;
	}
	for(i=0;i<=n;i++){
		c[i][0]=0;
	}

	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){

			if(P[i]==T[j]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='d';
			}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]='a';
			}
			else{
				c[i][j]=c[i][j-1];
				b[i][j]='l';
			}

		}
	}

	printf("\n\n");
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			printf("%6d %c",c[i][j],b[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	printf("\nLongest Common Subsequence:\n");
	printS(n,m);
}
void printS(int i,int j){
	if(i==0||j==0){
		return;
	}
	else{
		if(b[i][j]=='d'){
			printS(i-1,j-1);
			printf("%c",P[i]);
		}
		else if(b[i][j]=='a'){
			printS(i-1,j);
		}
		else if(b[i][j]=='l'){
			printS(i,j-1);
		}
	}
}

#include<stdio.h>

#define N 1000
int input[N][N];
int m,n,num;

int isExist(int,int);

int main(int argc, char* argv[])
{
	//FILE* fid;
	//fid=fopen("test.txt","r");
	freopen("test.txt","r",stdin);
	while(scanf("%d %d",&m,&n) != EOF)
	{
		scanf("%d",&num);
		int i,j;
		for(i = 0; i < m; i++)
			for(j = 0; j < n; j++)
				scanf("%d",&input[i][j]); 
		if(!isExist(0,n-1))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

int isExist(int row, int col)
{
	while(row < m && col >= 0)
	{
		if(input[row][col] == num)
			return 0;
		else if (input[row][col] > num)
			col--;
		else
			row++;
	}
	return 1;
}

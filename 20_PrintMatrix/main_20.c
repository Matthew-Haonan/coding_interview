#include <stdio.h>

#define Max 1000

void PrintMatrixClockWisely(int (*)[Max], int , int );
void PrintMatrixCircle(int (*)[Max], int , int , int );
int 
main(int argc, char *argv[])
{
	freopen("sample.txt","r",stdin);
	int row, column, i, j;
	int numbers[Max][Max];
	while(scanf("%d %d",&row,&column) != EOF)
	{
		for(i = 0; i < row; i++)
			for(j = 0; j < column; j++)
				scanf("%d",&numbers[i][j]);
		PrintMatrixClockWisely(numbers, column, row);
	}
	return 0;
}

void
PrintMatrixClockWisely(int numbers[][Max], int column, int row)
{
	if(numbers == NULL || column <= 0 || row <= 0)
		return;
	int start = 0;
	while(column > start * 2 && row > start * 2)
	{
		PrintMatrixCircle(numbers, column, row, start);
		++start;
	}
	printf("\n");
	return;
}

void 
PrintMatrixCircle(int numbers[][Max], int column, int row, int start)
{
	int endX = column - 1 - start;
	int endY = row - 1 - start;
	int i;
	//从左到右打印一行
	for(i = start; i <= endX; i ++)
		printf("%d ",numbers[start][i]);
	//从上到下打印一列，这个是有条件的
	if(start < endY)
	{
		for(i = start + 1; i <= endY; i ++)
			printf("%d ",numbers[i][endX]);
	}
	//从右到左打印一行，这个是有条件的
	if(start < endX)
	{
		for(i = endX - 1; i >= start; i--)
			printf("%d ",numbers[endY][i]);
	}
	//从下到上打印一列，这个有条件
	if(start < endX && start + 1 < endY)
	{
		for(i = endY - 1; i > start; i--)
			printf("%d ",numbers[i][start]);
	}
	return;
}

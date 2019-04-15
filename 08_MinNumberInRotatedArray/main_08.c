#include <stdio.h>
#include <stdlib.h>
#define N 1000

int BianLiMin(int*, int);
int MinValueOfArray(int *array, int length)
{
	if (array == NULL || length == 0)
	{
		fprintf(stderr,"Invalid Input!!!");
		return -1;
	}
	int LeftIndex = 0;
	int RightIndex = length - 1;
	int MidIndex = 0;  //把中间index的初值设置为0
	while (array[LeftIndex] >= array[RightIndex])
	{
		if (RightIndex - LeftIndex == 1)				//一上来要先确定终止条件
		{
			MidIndex = RightIndex;
			break;
		}
		MidIndex = (LeftIndex + RightIndex)/2;
		
		if (array[LeftIndex]  == array[RightIndex]
			&&array[MidIndex] == array[LeftIndex])
			return BianLiMin(array, length);			//如果两边和中间的值都相同，就用遍历法求最小（因为此时不知道最小是在Mid的哪一边）
		
		if (array[LeftIndex] <= array[MidIndex])
			LeftIndex = MidIndex;
		else if (array[MidIndex]  <= array[RightIndex])
			RightIndex = MidIndex;
	}
	return array[MidIndex];
}

int 
BianLiMin(int *array, int length)
{
	int i,result = array[0];
	for (i = 1; i < length; i++)
		if (result > array[i])
			result = array[i];
	return result;
}

int main (int argc, int *argv[])
{
	freopen("sample.txt","r",stdin);
	int i, num, array[N];
	int result;
	while(scanf("%d",&num) != EOF)
	{
		for(i = 0; i < num; i++)
			scanf("%d",&array[i]);
		result = MinValueOfArray(array,num);
		printf("Min value:%d\n",result);
	}
	exit(0);
}
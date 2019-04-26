#include <stdio.h>
#include <stdlib.h>

void ReOrderOddEven(int *, int);					//函数声明

int
main(int argc, char *argv[])
{
	freopen("sample.txt","r",stdin);
	int num, i;
	while(scanf("%d",&num) != EOF)
	{
		int *a = (int *)malloc(num * sizeof(int));
		for(i = 0; i < num; i++)
			scanf("%d", &a[i]);
		ReOrderOddEven(a,num);
		for(i = 0; i < num; i++)
			printf("%d%c", a[i],i == num - 1? '\n':' ');
	}
	return 0;
}

void 
ReOrderOddEven(int *arr, int length)
{
	if(arr == NULL || length <0)					//！！！要考虑到出错的处理
		return;
	int *Begin, *End;
	Begin = arr;									//数组的首地址赋给Begin
	End = arr + length - 1;							//数组的末地址赋给End
	while(Begin < End)								//只要前指针在后指针前面，任务就还没有完成
	{
		while(Begin < End && (*Begin & 0x01) != 0)	//不用取余的操作是因为，位操作的运算速度更快
			Begin ++;
		while(Begin < End && (*End & 0x01) == 0)
			End --;
		if (Begin < End)							//交换
		{
			int temp = *Begin;
			*Begin = *End;
			*End = temp;
		}
	}
	return;
}
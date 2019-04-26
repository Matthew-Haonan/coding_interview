#include <stdio.h>
#include <stdlib.h>

void ReOrder(int *, int, int (*func)(int));				//函数声明
int IsOddNotEven(int);
int IsPosNotNeg(int);

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
		ReOrder(a,num,IsPosNotNeg);					//第三个参数可以在“IsOddNotEven”和“IsPosNotNeg”中选择，不同的参数就是不同的重排规则
		for(i = 0; i < num; i++)
			printf("%d%c", a[i],i == num - 1? '\n':' ');
	}
	return 0;
}

//如此修改了函数之后，函数的功能不再局限于完成奇偶重排，
//修改最后一个参数，可以完成各种不同条件的重排，具有更好的扩展性
void 
ReOrder(int *arr, int length, int (*func)(int))		//最后一个参数为一个函数指针
{
	if(arr == NULL || length <0)					//！！！要考虑到出错的处理
		return;
	int *Begin, *End;
	Begin = arr;									//数组的首地址赋给Begin
	End = arr + length - 1;							//数组的末地址赋给End
	while(Begin < End)								//只要前指针在后指针前面，任务就还没有完成
	{
		while(Begin < End && func(*Begin))	//不用取余的操作是因为，位操作的运算速度更快
			Begin ++;
		while(Begin < End && !func(*End))
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

int IsOddNotEven(int data)							//奇偶重排条件
{
	return data & 0x01 == 1;
}

int IsPosNotNeg(int data)							//正负重排条件				
{
	return data > 0 ? 1 : 0;
}
#include <stdio.h>
#include <stdlib.h>

unsigned long long 						//保证是0-2^64-1之间的数，结果有足够空间
Fibonacci(unsigned int n)
{
	unsigned long long result[2] = {0,1};
	if (n < 2)
		return result[n];
	int i;
	unsigned long long fibN = 0;
	unsigned long long fibNMinusOne = 1;
	unsigned long long fibNMinusTwo = 0;
	
	for(i = 2 ; i <= n; i++)
	{
		fibN = fibNMinusOne + fibNMinusTwo;		//f(n) = f(n - 1) + f(n - 2)
		fibNMinusTwo = fibNMinusOne;			//当前的f(n - 1)是下一次循环的f(n - 2)
		fibNMinusOne = fibN;					//当前的f(n) 是下一次循环的f(n - 1)		
	}
	return fibN;
}

int 
main(int argc, char* argv[])
{
	freopen("sample.txt","r",stdin);
	int n;
	while(scanf("%d",&n) != EOF)
	{
		unsigned long long result;
		printf("%llu\n",Fibonacci(n));
	}
	exit(0);									//进程正常退出
}
#include <stdio.h>

int 
NumberOf1InBinary(int n)
{
	int count = 0;
	while(n)
	{
		count++;
		n = n & (n - 1);			//该方法比下面注释掉的普通方法的优势在于：
	}								//普通方法要循环32次（flag的位数），优化方法循环次数等于1的个数
	/*
	int count = 0;
	unsigned int flag = 1;			//flag是一个无符号数字，左移右移都是添0
	while(flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	*/
	return count;
}

int 
main(int argc, char* argv[])
{
	freopen("sample.txt","r",stdin);
	int n;
	while(scanf("%d",&n) != EOF)
	{
		printf("%d\n",NumberOf1InBinary(n));
	}
	return 0;
}
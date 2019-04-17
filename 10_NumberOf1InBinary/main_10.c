#include <stdio.h>

int 
NumberOf1InBinary(int n)
{
	int count = 0;
	unsigned int flag = 1;			//flag是一个无符号数字，左移右移都是添0
	while(flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
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
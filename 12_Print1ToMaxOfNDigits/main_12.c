#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

bool Increase(char*);
void PrintNumber(char*);
int 
main(int argc, char* argv[])
{
	freopen("sample.txt","r",stdin);
	int n;
	while(scanf("%d",&n) != EOF)
	{
		char *number = (char*)malloc((n + 1)*sizeof(char));	//记得为“\0”申请一个空间
		memset(number,'0',n);				//！！！给新申请的char内存清'0'
		number[n] = '\0';					//！！！手动在最后一个位置加'\0'
		while(!Increase(number))			//如果进位没有出现最高位溢出，循环继续
			PrintNumber(number);
		printf("\n");
	}
	return 0;
}

bool Increase(char* number)
{
	bool overflow = false;					//初始标志是不溢出
	int Length = strlen(number);
	int i,carry = 0, sum;
	for(i = Length - 1; i >= 0; i--)		//最低位加1，安排一个循环的目的是进位后，除最低位其他位也会加1
	{
		sum = number[i] - '0' + carry;		//没有写成number[i] = number[i] - '0' + carry的原因是number[i]可能会从9变成10，而每一个char要存的数是0-9
		if (i == Length - 1)
			sum++;							//！！！最低位+1
		carry = 0;							//进位结束后，进位位清0
		if (sum >= 10)
		{
			if(i == 0)						//如果是最高位进位的话，就溢出了		
			{
				overflow = true;			//溢出
				break;
			}
			else							//其他位正常进位
			{
				carry = 1 ;					//记得一会清0
				number[i] = '0';
			}
		}
		else
		{
			number[i] = sum + '0';			//sum没有超过10的话，正常存1-9就完事了
		}
	}
	
	return overflow;
}

void PrintNumber(char* number)					
{
	//bool isBegin0 = true;
	int Length = strlen(number);
	int i;
	for(i = 0; i < Length; i++)
	{
		if (number[i] != '0')
			break;
	}
	printf("%s ",&number[i]);
	
}

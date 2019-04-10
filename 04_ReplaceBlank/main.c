#include<stdio.h>
#include<string.h>

#define N 1000

void ReplaceBlank(char*,int);
int main(int argc, char* argv[])
{
	//char []= "ffff"
	char str[N];
	freopen("test.txt","r",stdin);
	
	int count = 0,i = 0;
	while (scanf("%c",&str[i]) != EOF)
	{
		if(str[i] == ' ')
			count ++;
		else{}
		i ++;
	}
	str[i] = '\0';   // 注意不要丢了这一句
	
	ReplaceBlank(str,count);
	printf("%s",str);
}

void ReplaceBlank(char str[],int count)
{
	int num = strlen(str); //不包含最后的'/0'
	char *pt1,*pt2;
	pt1 = &str[num + 1];
	pt2 = &str[num + 2*count + 1];  //有多少个空格，就会增加2*count个字节空间
	while (pt1 != pt2)
	{
		if (*pt1 == ' ')
		{
			pt1--;
			*pt2-- = '0';
			*pt2-- = '2';
			*pt2-- = '%';
		}
		else
		{
			*pt2-- = *pt1--;
		}
			
	}
}

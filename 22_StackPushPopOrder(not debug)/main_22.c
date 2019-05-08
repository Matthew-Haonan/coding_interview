#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define bool int
#define false 0
#define true 1
/*
1、根据pop的内容遍历，遍历完或者push的内容提前走完就出循环
2、如果栈空了并且pop遍历完了，说明是弹出序列
*/

extern void init(Stack *s);
extern int empty(Stack *s);
extern void  pop(Stack *s);
extern void push(Stack *s, datatype element);
extern datatype top(Stack *s);

bool
IsPopOrder(const int *pPush, const int *pPop, int nLength)
{
	bool IsPossible = false;
	if(pPush != NULL && pPop != NULL  && nLength > 0)
	{
		const int *pNextPush = pPush;
		const int *pNextPop = pPop;
		Stack *s =(Stack *)malloc(sizeof(Stack));
		init(s);
		while(pNextPop - pPop < nLength)
		{
			while(empty(s) || top(s) != *pNextPop)
			{
				if(pNextPush - pPush == nLength)	//如果压栈序列遍历完了，那也没得玩了
					break;
				push(s,*pNextPush);					//有的玩就压栈
				pNextPush++;
			}
			if(top(s) != *pNextPop)
				break;
			pop(s);
			pNextPop++;
		}
		if (empty(s) && pNextPop -pPop == nLength )
			IsPossible = true;
	}
	return IsPossible;
}

int 
main(int argc, char *argv[])
{
	freopen("sample.txt","r",stdin);
	int i,num,nLength;
	while(scanf("%d",&num) != EOF)
	{
		nLength = num*sizeof(int);
		int *pPush = (int *)malloc(nLength);
		int *pPop = (int *)malloc(nLength);
		for(i = 0; i < num; i++)
			scanf("%d",&pPush[i]);
		for(i = 0; i < num; i++)
			scanf("%d",&pPop[i]);
		//bool result = IsPopOrder(pPush,pPop,nLength);
		if(IsPopOrder(pPush,pPop,nLength))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define max 1000
/***********************************标准栈start******************/
typedef int datatype;
typedef struct stack
{
	datatype data[max];
	int top ;
}Stack;

void
init(Stack *s)
{
	s -> top = -1;
}

void  
pop(Stack *s)
{
	if (s -> top < 0)
	{
		printf("Stack is empty!\n");
		return;
	}
	s -> top--;
	return;
}

void 
push(Stack *s, datatype element)
{
	if (s -> top > max - 2) 
	{
		printf("Full!\n");
		return;
	}
	s -> top++;
	s -> data[s -> top] = element;
	return;
}

datatype
top(Stack *s)
{
	if (s -> top < 0)
	{
		printf("Stack is empty!\n");
		return -1;
	}
	return s -> data[s -> top];
}
/***********************************标准栈end******************/

/***********************************With Min栈start******************/

void
newpush(Stack *s, Stack *assist, datatype value)
{
	push(s, value);
	if(assist -> top == -1 || top(assist) > value)
		push(assist, value);
	else
		push(assist, top(assist));
}

void
newpop(Stack *s, Stack *assist)
{
	pop(s);
	pop(assist);
}

datatype
min(Stack *assist)
{
	if(assist -> top == -1)
	{
		printf("assist stack empty");
		return -1;
	}
	return top(assist);
}
/***********************************With Min栈end******************/

int 
main(int argc, char *argv[])
{
	freopen("sample.txt","r",stdin);
	int num, value;
	char ch;
	Stack *s = (Stack *)malloc(sizeof(Stack));
	Stack *assist = (Stack *)malloc(sizeof(Stack));
	init(s);
	init(assist);
	while(scanf("%d",&num) != EOF)
	{
		int i;
		for(i = 0; i < num; i++)
		{
			scanf(" %c",&ch);				//！！！这里%c前有一个空格 white—space
			if (ch == 's')
			{
				scanf("%d",&value);
				newpush(s, assist, value);
			}
			else if(ch == 'o')
			{
				newpop(s,assist);
			}
			else
			{}
			printf("%d\n",min(assist));
		}
	}
	return 0;
}
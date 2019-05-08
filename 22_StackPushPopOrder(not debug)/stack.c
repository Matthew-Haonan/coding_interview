#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void
init(Stack *s)
{
	s -> top = -1;
}

int 
empty(Stack *s)
{
	if(s -> top == -1)
		return 1;
	else 
		return 0;
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
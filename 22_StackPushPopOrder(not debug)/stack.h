#ifndef _STACK_H
#define _STACK_H

#define max 1000
/***********************************标准栈start******************/
typedef int datatype;
typedef struct stack
{
	datatype data[max];
	int top ;
}Stack;

void init(Stack *s);
int empty(Stack *s);
void  pop(Stack *s);
void push(Stack *s, datatype element);
datatype top(Stack *s);

#endif

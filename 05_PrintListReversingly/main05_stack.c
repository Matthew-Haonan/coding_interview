#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 1000


typedef struct node     
{
	int data;
	struct node *next;
}Listnode;

/*****************有关栈的内容*******************/
#define maxsize 1000
typedef Listnode* datatype;  
typedef struct stack
{
	datatype data[maxsize];
	int top;
}MyStack;

void Init(MyStack *s)
{
	s->top = -1;
}
bool IsEmpty(MyStack *s)
{
	if (s->top == -1)
		return true;
	else
		return false;
}
bool IsFull(MyStack *s)
{
	if(s->top == maxsize - 1)
		return true;
	else
		return false;
}

void Push(MyStack *s,datatype Element)
{
	if(!IsFull(s))
	{
		s->top ++;
		s->data[s->top] = Element;
	}
	else
		printf("栈满\n");
}
//仅出栈，不输出值
void Pop(MyStack *s)
{
	if(!IsEmpty(s))
	{
		
		s->top --;
	}
	else
		printf("栈空\n");
}
//仅输出值，不出栈
datatype Top(MyStack *s)
{
	if(!IsEmpty(s))
	{
		return s->data[s->top];
	}
	else
	{
		printf("栈空\n");
		return NULL;
	}
}
/**********************栈的内容结束************/



void ListTraverse(Listnode *);
int main(int argc, char* argv[])
{
	freopen("test.txt","r",stdin);
	int input,count = 0;
	int a[N]; 
	Listnode *head, *cur, *tmp;
	head = (Listnode *)malloc(sizeof(Listnode));
	head->next = NULL;
	cur = head;
	scanf("%d",&input);
	while(input != -1)
	{
		count++;				//统计有多少个数据
		tmp = (Listnode *)malloc(sizeof(Listnode));
		tmp->data = input;
		tmp->next = NULL;		//把最新输入的数字放在一个链表节点里，并为next赋初值NULL
		cur->next = tmp;		//把新节点加到当前节点的后面
		cur = tmp;				//移动当前节点
		scanf("%d",&input);
	}
	//ListTraverse(head);
	MyStack *s;
	s = (MyStack *)malloc(sizeof(MyStack));		//第一次代码中遗漏,指针没有明确的内存地址空间，必须在堆上申请内存
	Init(s);				//第一次代码中遗漏
	cur = head->next;
	while(cur != NULL)
	{
		Push(s,cur);
		cur = cur->next;
	}
	while(!IsEmpty(s))
	{
		tmp = Top(s);
		printf("%d\n",tmp->data);
		Pop(s);
	}
	return 0;
}

void ListTraverse(Listnode *Lianbiao)
{
	Listnode *p = Lianbiao->next;	//链表的第一个节点（不算head节点）的指针暂存到p中 
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	return ;
}
#include<stdio.h>
#include<stdlib.h>
#define N 1000

typedef struct node     // 复习typedef的基础知识！！！！！！！
{
	int data;
	struct node *next;
}Listnode;

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
	cur = head->next;
	int i =0;
	while(cur != NULL)
	{
		a[i] = cur->data;
		i++;
		cur = cur->next;
	}
	for (i = count-1; i >= 0; i--)
		printf("%d\n",a[i]);
	
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
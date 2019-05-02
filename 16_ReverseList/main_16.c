#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
	int value;
	struct listnode *next;
}ListNode;

struct listnode *CreateList(int num)
{
	if (0 == num) return NULL;				//链表节点数为0
	int val, i;
	ListNode *pHead = (ListNode *)malloc(sizeof(ListNode));
	pHead -> value = scanf("%d",&val);
	pHead -> next = NULL;
	ListNode *tail = pHead;
	for(i = 1; i < num; i++)
	{
		ListNode *newList = (ListNode *)malloc(sizeof(ListNode));
		scanf("%d",&val);
		newList -> value = val;
		newList -> next = NULL;
		tail -> next = newList;
		tail = tail -> next;
	}
	return pHead;
}

ListNode *ReverseList(ListNode *pHead)
{
	ListNode *pReverseHead = NULL;
	ListNode *pCur = pHead;
	ListNode *pPre = NULL;
	while(pCur != NULL)
	{
		ListNode *pNext = pCur -> next;
		if(pNext == NULL) 
			pReverseHead = pCur;
		pCur -> next = pPre;			//前一个节点的地址赋给当前节点的next，即调换顺序
		pPre = pCur;
		pCur = pNext;
	}
	return pReverseHead;
}

void ListTraverse(ListNode *pHead)
{
	if(pHead == NULL) 
	{
		printf("NULL\n");
		return;
	}
	//printf("%d",pHead -> value);
	ListNode *temp = pHead;
	while(temp != NULL)
	{
		printf("%d ",temp ->value);
		temp = temp -> next;
	}
	printf("\n");
	return;
}

int 
main(int argc, char *argv[])				//对*argv[]理解
{
	freopen("sample.txt","r",stdin);
	int num;
	while(scanf("%d",&num) != EOF)
	{
		ListNode *Head = CreateList(num);
		ListTraverse(Head);
		ListNode *revHead = ReverseList(Head);
		ListTraverse(revHead);
	}
}
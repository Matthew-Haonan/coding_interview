#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
	int value;
	struct listnode *next;
}ListNode, *pListNode;

ListNode
*CreateList(int num)
{
	if(0 == num)
		return NULL;
	int i;
	ListNode *pHead = (ListNode *)malloc(sizeof(ListNode));
	ListNode *pTail = pHead;
	scanf("%d",&(pHead -> value));
	pHead -> next = NULL;
	for(i = 1; i < num; i++)
	{
		ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
		scanf("%d",&(NewNode -> value));
		NewNode -> next = NULL;
		pTail -> next = NewNode;
		pTail = NewNode;
	}
	return pHead;
}

void ListTraverse(ListNode *Head)
{
	if (Head == NULL)
	{	
		printf("NULL\n");
		return;
	}
	ListNode *p = Head;
	while (p != NULL)
	{
		printf("%d ", p -> value);
		p = p -> next;
	}
	printf("\n");
	return;
}
ListNode 
*merge(ListNode *pHead1, ListNode *pHead2)
{
	ListNode *pMergeHead = NULL;
	if(pHead1 == NULL && pHead2 == NULL)
		return NULL;
	else if(pHead1 == NULL)
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;
	
	ListNode *p = pHead1;
	ListNode *m = pHead2;
	ListNode *pPre = NULL;
	if(p -> value <= m -> value)
	{
		pMergeHead = p;
		pPre = p;
		p = p -> next;
	}
	else
	{
		pMergeHead = m;
		pPre = m;
		m = m -> next;
	}
		
	while(p != NULL && m != NULL)
	{
		if(p -> value <= m -> value)
		{
			pPre -> next = p;			//链表节点连起来
			pPre = p;					//移动pPre
			p = p -> next;				//移动p
		}
		else
		{
			pPre -> next = m;			//链表节点连起来
			pPre = m;					//移动pPre
			m = m -> next;				//移动m
		}
	}
	while(p != NULL)
	{
		pPre -> next = p;			//链表节点连起来
		pPre = p;					//移动pPre
		p = p -> next;				//移动p
	}
	while(m != NULL)
	{
		pPre -> next = m;			//链表节点连起来
		pPre = m;					//移动pPre
		m = m -> next;				//移动m
	}
	return pMergeHead;
}

int 
main(int argc, char *argv[])
{
	freopen("sample.txt","r",stdin);
	int num1,num2;
	while(scanf("%d",&num1) != EOF)
	{
		scanf("%d",&num2);
		ListNode *pHead1 = CreateList(num1);
		ListNode *pHead2 = CreateList(num2);
		ListTraverse(pHead1);
		ListTraverse(pHead2);
		ListNode *pMergeHead = merge(pHead1, pHead2);
		ListTraverse(pMergeHead);
	}
}

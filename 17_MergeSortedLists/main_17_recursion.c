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
	if(pHead1 == NULL)
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;
	
	if(pHead1 -> value <= pHead2 -> value)
	{
		pMergeHead = pHead1;
		pMergeHead -> next = merge(pHead1 -> next, pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead -> next = merge(pHead1 , pHead2 -> next);
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

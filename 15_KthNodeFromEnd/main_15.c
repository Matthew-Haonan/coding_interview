#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
	int value;
	struct listnode *next;
}ListNode, *pListNode;

ListNode *CreateList(int num)
{
	int i, value;
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head -> next = NULL;
	ListNode *tail = head;
	for(i = 0; i < num; i++)
	{
		scanf("%d", &value);
		ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
		NewNode -> value = value;
		NewNode -> next = NULL;
		tail -> next = NewNode;
		tail = NewNode;
	}
	return head;
}

void ListTraverse(ListNode *pHead)
{
	pListNode p = pHead -> next;
	if(p == NULL)
		printf("链表为空！");
	else
	{
		while(p != NULL)
		{
			printf("%d ",p -> value);
			p = p -> next; 
		}
		printf("\n");
	}
	return;
}
ListNode *FindKthFromEnd(ListNode *pHead, int k)
{
	if(pHead == NULL || k <= 0)						//这个地方和书上的不一致，书上是不是少考虑了k小于0的情况
		return NULL;
	int i;
	ListNode *pFirst = pHead -> next;
	ListNode *pSecond = pHead -> next;
	for (i = 0; i < k-1; i++)
	{
		if(pFirst == NULL)							//防止链表中的节点少于k个 ？？不太确定
			return NULL;
		pFirst = pFirst -> next;
	}
	while(pFirst -> next != NULL)
	{
		pFirst = pFirst -> next;
		pSecond = pSecond -> next;
	}	
	return pSecond;
}
int
main(int argc, int *argv[])
{
	freopen("sample.txt","r",stdin);
	int num, i;
	int k;
	ListNode *KthToTail = (ListNode *)malloc(sizeof(ListNode));
	ListNode *pHead = (ListNode *)malloc(sizeof(ListNode));
	while(scanf("%d",&num) != EOF)
	{
		scanf("%d",&k);						//要找的倒数第k个节点
		pHead = CreateList(num);
		//ListTraverse(pHead);
		KthToTail = FindKthFromEnd(pHead,k);
		if(KthToTail == NULL)
			printf("NULL\n");
		else
			printf("%d\n", KthToTail->value);
	}
	return 0;
}
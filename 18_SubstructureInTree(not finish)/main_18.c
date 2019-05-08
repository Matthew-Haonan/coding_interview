#include <stdio.h>
#include <stdlib.h>

#define NULLKEY '#'

typedef struct binarytreenode
{
	int m_nValue;
	struct binarytreenode *m_pLeft;
	struct binarytreenode *m_pRight;
}BinaryTreeNode;

BinaryTreeNode
*preCreateTree()
{
	char input;
	BinaryTreeNode *root;
	scanf("%c",&input);
	if (input == NULLKEY)				//int和char的比较 ？？
	{
		root = NULL;
		return root;
	}
	else
	{
		root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
		root -> m_nValue = input;
		root -> m_pLeft = preCreateTree();
		root -> m_pRight = preCreateTree();
		return root;
	}
	
}

void
preVisitBinaryTree(BinaryTreeNode *root)
{
	if(!root)
	{
		printf("%c ",root -> m_nValue);
		
		preVisitBinaryTree(root -> m_pLeft);
		
		preVisitBinaryTree(root -> m_pRight);
	}
	printf("\n");
	return;
}
int 
main(int argc, char *argv[])
{
	freopen("sample.txt","r",stdin);
	int num,subnum;
	BinaryTreeNode *root;
	while(scanf("%d",&num))
	{
		//scanf("%d",&subnum);
		root = preCreateTree();
		preVisitBinaryTree(root);
		
	}
	return 0;
}
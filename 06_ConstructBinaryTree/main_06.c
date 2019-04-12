//前序遍历第一个节点确定根节点，然后在中序遍历中寻找根节点，从而确定左、右子树，对左右子树递归（recursive）进行
#include<stdio.h>
#include<stdlib.h>
#define N 1000

int flag = 1; 		//是否为二叉树的标志

typedef struct node						//节点定义
{
	int nodevalue;
	struct node *leftchild;
	struct node *rightchild;
}Node,*pNode;							//节点结构体的两个别名，方便以两种方式使用（指针和非指针）

pNode ConstructBinaryTree(int *preTree, int *midTree, int length)  //注意前两个参数的类型，不是pNode
{
	if(length < 1)
		return NULL;								//非常重要，记住递归是需要停止条件的！！！！！！！
	/*第一步是确定本次操作的根节点*/
	pNode root = (pNode)malloc(sizeof(Node));		//在堆内存上为指针变量申请空间	
	root->nodevalue = *preTree;						//前序遍历的第一个节点是根节点
	root->leftchild = NULL;
	root->rightchild = NULL;
	
	/*第二步是在中序遍历中寻找根节点，同时记录左子树的长度（右子树长度也能通过“总长度-左子树长度-1”得到）*/
	int i = 0,count = 0;
	while(*preTree != *(midTree+i))
	{
		count ++;
		if(count >= length)		//如果超出寻找范围还没找到根节点，那就返回NULL吧，这个二叉树不对
		{
			flag = 0;			//标志位置为0，不是一个二叉树
			return NULL;
		}			
		else
			i++;
	}
	
	/*第三步是递归该函数（为什么可以开始递归了呢：观察本函数的三个参数，在完成前两步之后，
	都能确定左、右子树各自的前序遍历、中序遍历和长度，因此可以把一个大问题分解成一个个的小问题了） */
	root->leftchild = ConstructBinaryTree(preTree + 1, midTree, count);  //注意递归调用后，要把值传给root的左右节点，怎么能把这个忘记呢！！！！
	root->rightchild = ConstructBinaryTree(preTree + 1 + count, midTree + count + 1, length - count - 1);  //长度要根据前序遍历和中序遍历的特点来确定
	return root;				//最后return的这个节点就是二叉树的根节点，这是完成所有递归后的一个返回值，也就是第一个根节点
}
void TraverseBinaryPostOrder(pNode root)   //遍历函数的实现还是依靠递归
{
	if(root == NULL)
		return;
	TraverseBinaryPostOrder(root->leftchild);
	TraverseBinaryPostOrder(root->rightchild);
	printf("%d ",root->nodevalue);
}

int main(int argc, char* argv[]) //这次在linux命令行操作试试加入变量 熟悉一下！！！！！！ 
{
	freopen("sample.txt","r",stdin);
	/*
	printf("%d",argc);			//just for test
	int j;
	for (j = 0; j < argc; j++)
	{
		printf("%s\n",argv[j]);
	}
	*/
	int TreeLength;
	while(scanf("%d",&TreeLength) != EOF)	//扫描的第一个参数是树的长度
	{
		int i;
		int PreOrder[N],InOrder[N];
		for(i = 0; i < TreeLength; i++)
		{
			scanf("%d",&PreOrder[i]);
		}
		for(i = 0; i < TreeLength; i++)
		{
			scanf("%d",&InOrder[i]);		//因为scanf的参数是%d,因此white-space都被跳过了，只有在%c才能读进来
		}
		pNode root = ConstructBinaryTree(PreOrder,InOrder,TreeLength);
		if(flag == 1)
			TraverseBinaryPostOrder(root);
		else
			printf("No");
		printf("\n");
	}
	return 0;
}
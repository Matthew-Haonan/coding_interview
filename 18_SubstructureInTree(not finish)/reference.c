#include <stdio.h>
#include <stdlib.h>

/* 定义数据类型 */
typedef char TypeData ;

/* 定义二叉树 */
typedef struct stBiTreeNode
{
    TypeData data;
    struct stBiTreeNode *lchild, *rchild;
}BITREENODE;

/* 初始化二叉树 */
BITREENODE* createBiTree()
{
    char chTempData = 0;

    BITREENODE *pstNewNode = NULL;

    scanf("%c",&chTempData);
    if(chTempData == '#')
    {
        pstNewNode = NULL;
    }
    else
    {
        /* 分配内存 */
        pstNewNode = (BITREENODE*)malloc(sizeof(BITREENODE) + 1);
        pstNewNode->data = chTempData;

        /* 递归调用产生二叉树 */
        pstNewNode->lchild = createBiTree();
        pstNewNode->rchild = createBiTree();
    }

    return pstNewNode;
}

/* 前序遍历二叉树 */
int preVisitBiTree(BITREENODE* InRoot)
{
    if(InRoot)
    {
        /* 先遍历根节点 */
        printf("%c ",InRoot->data);

        /* 遍历左子树 */
        preVisitBiTree(InRoot->lchild);

        /* 遍历右子树 */
        preVisitBiTree(InRoot->rchild);

    }
    return 0;
}


/* 中序遍历二叉树 */
int inVisitBiTree(BITREENODE* InRoot)
{
    if(InRoot)
    {
        /* 遍历左子树 */
        preVisitBiTree(InRoot->lchild);


        /* 先遍历根节点 */
        printf("%c ",InRoot->data);

        /* 遍历右子树 */
        preVisitBiTree(InRoot->rchild);

    }
    return 0;
}

/* 后序遍历二叉树 */
int postVisitBiTree(BITREENODE* InRoot)
{
    if(InRoot)
    {
        /* 遍历左子树 */
        preVisitBiTree(InRoot->lchild);


        /* 遍历右子树 */
        preVisitBiTree(InRoot->rchild);


        /* 先遍历根节点 */
        printf("%c ",InRoot->data);

    }
    return 0;
}


int main(void)
{
	freopen("sample.txt","r",stdin);
    BITREENODE* pstRoot;

    /* 构造一个二叉树 */
    pstRoot = createBiTree();

    /* 前序遍历左子树 */
    preVisitBiTree(pstRoot);

    printf("\n");

    /* 中序遍历左子树 */
    inVisitBiTree(pstRoot);

    printf("\n");

    /* 后序遍历左子树 */
    postVisitBiTree(pstRoot);
    return 0;
}

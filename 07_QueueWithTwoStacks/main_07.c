#include <stdio.h>
#include <string.h>
#define N 1000
int main (int argc, char *argv[])
{
	freopen("sample.txt","r",stdin);
	int OperateNum ,stack0[N],stack1[N];		//用数组当栈用，C语言没办法
	int i,top0 = -1 ,top1 = -1;
	char input[5];								//存储PUSH 和 POP，所以5个空间就够了
	while(scanf("%d",&OperateNum) != EOF) 		//读进来操作多少次
	{
		for(i = 0; i < OperateNum; i++)						
		{
			scanf("%s",input);
			if(!strcmp(input,"PUSH"))			//如果是PUSH，再读下一个数字内容进stack0
				scanf("%d",&stack0[++top0]);
			else if(-1 != top1)					//如果是POP，并且stack1还没空，弹出stack1最上面的元素
				printf("%d\n",stack1[top1--]);
			else if(-1 == top1 && -1 == top0)	//第一个判断可以不要，因为上面的elseif已经排除了-1和top1的相等
			{
				printf("-1\n");
				break;							//注意此时还不能return，因为sample里可能还有新一波的数据，需要等到最外层while遇到EOF再return
			}
			else								//此时为stack1见底（top1等于-1），stack0还有东西（top0不等于-1），要把stack0的内容放到stack1
			{
				while(-1 != top0)
					stack1[++top1] = stack0[top0--];
				printf("%d\n",stack1[top1--]);	//不要忘记这一句，转移完了要把队列头输出出来
			}
		}
		printf("\n");
	}

	return 0;
}
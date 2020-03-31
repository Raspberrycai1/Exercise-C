/*5. 链表合并
题目描述:已有 a、b 两个链表，每个链表中的结点包括学号、成绩。要求把两个链表合并，按学号升序排列。
输入:
第一行，a、b 两个链表元素的数量 N、M,用空格隔开.接下来 N 行是 a 的数据,然后M行是 b 的数据 每行数据由学号和成绩两部分组成
输出:
按照学号升序排列的数据
样例输入
2 3
5 100
6 89
3 82
4 95
2 10
样例输出
2 10
3 82
4 95
5 100
6 89
*/

# include <stdio.h>
# include <malloc.h>

typedef struct Student
{
	int sid;
	int score;
	struct Student* pNext;
}STU, * PSTU;

void getInput(PSTU,PSTU);
void ListMerge(PSTU,PSTU);
void ListSort(PSTU);
void traverseList(PSTU);

int main()
{
	PSTU pHeadA = (PSTU)malloc(sizeof(STU));
	PSTU pHeadB = (PSTU)malloc(sizeof(STU));

	getInput(pHeadA,pHeadB);
	ListMerge(pHeadA,pHeadB);
	ListSort(pHeadA);
	traverseList(pHeadA);

	return 0;
}

void getInput(PSTU pHeadA,PSTU pHeadB)
{
	int N,M;
	int i;
	PSTU pTailA = pHeadA;
	pTailA->pNext = NULL;
	PSTU pTailB = pHeadB;
	pTailB->pNext = NULL;

	printf("第一行，a、b 两个链表元素的数量 N、M,用空格隔开.接下来 N 行是 a 的数据,然后M行是 b 的数据 每行数据由学号和成绩两部分组成:\n");
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++)
	{
		PSTU pNew = (PSTU)malloc(sizeof(STU));
		printf("请输入a链表第%d个元素的学号和成绩:",i+1);
		scanf("%d %d",&pNew->sid,&pNew->score);
		pTailA->pNext = pNew;
		pNew->pNext = NULL;
		pTailA = pNew;
	}
	for(i=0;i<M;i++)
	{
		PSTU pNew = (PSTU)malloc(sizeof(STU));		
		printf("请输入b链表第%d个元素的学号和成绩:",i+1);
		scanf("%d %d",&pNew->sid,&pNew->score);
		pTailB->pNext = pNew;
		pNew->pNext = NULL;
		pTailB = pNew;
	}
}

//找到a链表的尾节点
void ListMerge(PSTU pHeadA, PSTU pHeadB)
{
	PSTU p = pHeadA->pNext;
	PSTU r = pHeadB->pNext;
	
	while(NULL != p->pNext)//p的指针域为空,证明指向尾节点
	{
		p = p->pNext;
	}
	p->pNext = r;
}

//按学号升序排列:冒泡排序
void ListSort(PSTU pHead)
{
	//需要知道链表长度？不用
	PSTU p,q;	
	for( p=pHead->pNext; NULL != p; p=p->pNext)
		for(q=p->pNext; NULL != q; q=q->pNext)
		{
			if(p->sid > q->sid)
			{
				int temp1 = p->score;
				p->score = q->score;
				q->score = temp1;

				int temp2 = p->sid;
				p->sid = q->sid;
				q->sid = temp2;
			}
		}
}
//多输出一行0 0,那是pHead
void traverseList(PSTU pHeadA)
{
	PSTU p = pHeadA->pNext;
	while(NULL != p)
	{
		printf("%d %d\n",p->sid,p->score);
		p = p->pNext;
	}
	return;
}

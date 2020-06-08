//郝斌 24_链表创建和链表遍历算法的演示
# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>//exit
# include <stdbool.h>//bool

//节点的表示：数据域和指针域
//指针域是指向了后面的整体，指向了一个和他本身类型一样的变量

typedef struct Node //typedef 别名
{
	int data;	//数据域
	struct Node* pNext;//指针域
}NODE, *PNODE; 
//NODE是一个结构体变量，PNODE是指向结构体变量的一个指针变量,存放的是第一个字节的地址(地址是4字节)(其类型：struct Node *)
//所有的指针变量只占4个字节，用第一个字节的地址表示整个变量的地址

//调用一个链表只需要知道他的头节点的地址/头指针

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);
bool delete_list(PNODE pHead, int pos, int* pVal);

int main(void)
{
	PNODE pHead = NULL;
	int val;//保存被删节点的数据

	pHead = create_list();//创建一个非循环单链表，并将该链表的头结点的地址赋给pHead(跨函数使用内存——malloc)
	traverse_list(pHead);
	insert_list(pHead,2,33);
	/*	
	if( delete_list(pHead, 4, &val) )
	{
		printf("删除成功，您删除的元素是：%d\n",val);
	}
	else
	{
		printf("删除失败!要删除的元素不存在\n");
	}*/
	traverse_list(pHead);
	return 0;
}

PNODE create_list()
{
	int len;
	int i;
	int val;

	//分配了一个不存放有效数据的头结点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配内存失败,程序终止\n");
		exit(-1); //<stdlib.h>
	}
	//pTail永远指向尾节点
	PNODE pTail = pHead;
	pTail->pNext = NULL; //若只有一个头结点,才能保证

	printf("请输入需要生成的链表节点的个数：len =");
	scanf("%d",&len);

	for(i=0; i<len; i++)
	{
		printf("请输入第%d个节点的值",i+1);
		scanf("%d",&val);
		//每次都声明定义
		PNODE pNew = (PNODE)malloc(sizeof(NODE));

		if (NULL == pHead)
		{
			printf("分配内存失败,程序终止\n");
			exit(-1); //<stdlib.h>
		}
		pNew->data = val;
		pTail->pNext = pNew; 
		//挂到pTail后面
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail=pNew;
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while(p!= NULL)
	{
		printf("%d ",p->data);
		p=p->pNext;
	}
	printf("\n");
	return;
}
//链表为空：只有一个头结点，没有任何有效节点

//在pHead所指向链表的第pos个节点的前面插入一个新的节点，该节点的值是val,并且pos的值是从1开始(避免下标0的混淆)
bool insert_list(PNODE pHead, int pos, int val)
{
	//需要考虑pos：如果只有5个节点，pos可以是6,但不可以是7，求长度，再比较
	//下面一段不需判断链表空/满，也不需要遍历，避免了所有异常情况：实现了p已经指向了第pos-1个节点
	int i = 0;
	PNODE p = pHead;

	while(NULL!=p && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	if(i>pos-1 || NULL==p)
		return false;
	
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("动态分配内存失败！\n");
		exit(-1);
	}
	pNew->data=val;
	PNODE q = p->pNext;//定义临时节点
	p->pNext = pNew;
	pNew->pNext = q;

	return true;
}
//删除
bool delete_list(PNODE pHead, int pos, int* pVal)
{
	int i = 0;
	PNODE p = pHead;

	while(NULL !=p->pNext && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	if(i>pos-1 || NULL == p->pNext)
		return false;
	PNODE q = p->pNext;
	*pVal = q->data;//把数据保存下来
	
	//删除p节点后面的节点
	p->pNext = p->pNext->pNext;
	free(q);
	q=NULL;

	return true;
}

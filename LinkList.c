
# include <stdio.h>

//节点的表示：数据域和指针域
//指针域是指向了后面的整体，指向了和他本身类型一样的变量

typedef struct Node //typedef 别名
{
	int data;
	struct Node* pNext;//指向了一个和他本身一样的变量
}NODE, *PNODE; //NODE是一个结构体变量，PNODE是指向结构体变量的一个指针(其类型：struct Node *)

int main(void)
{

	return 0;
}

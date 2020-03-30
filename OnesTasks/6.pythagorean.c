/*6勾股数是一组三个自然数，a < b < c，以这三个数为三角形的三条边能够形成一个直角三角形
输出所有 a + b + c < = 1000 的勾股数: a 小的先输出；a 相同的，b 小的先输出。
输入: 无
输出: 每行为一组勾股数，用空格隔开
样例输入
无
样例输出
3 4 5
5 12 13
6 8 10
**************/
/* 思路(2020/3/30)
1. 找到符合条件的勾股数
   并放到一个结构体数组中
2. 按条件排序(换位置)
3. 遍历输出
***********/

# include <stdio.h> //scanf, printf
# include <stdlib.h> //malloc, calloc, realloc, free

typedef struct num3
{
	int pynum[3];
}NARR, PNARR;

PNARR getPyNum();
void changePose(PNARR);
void traverse(PNARR);

int main(void)
{
	PNARR pHead;
	pHead = getPyNum();
	changePose(pHead);
	traverse(pHead);

	return 0;
}

PNARR getPyNum()
{
	PNARR pHead = (PNARR)malloc(sizeof(NARR)*10);
	int i;
	//如何判断内存是否用完？用一个变量i计数

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
# include <math.h> //sqrt, pow

# define SIZE 10

typedef struct num3
{
	int pynum[3];
}NARR,* PNARR;

PNARR getPyNum();
void changePose(PNARR);
void traverse(PNARR);

int main(void)
{
	printf("开始");
	PNARR pHead;
	printf("运行到函数");
	pHead = getPyNum();
	//changePose(pHead);
	//traverse(pHead);

	return 0;
}
PNARR getPyNum()
{
	int i=0;//如何判断内存是否用完？用一个变量i计数
	int length = SIZE;
	int a, b, c;
	int sum = pow(a,2)+pow(b,2)+pow(c,2);

	PNARR pHead = (PNARR)malloc(sizeof(NARR)*SIZE);
	if(NULL == pHead)
	{
		free(pHead);
		printf("分配内存失败");
		exit(-1);
	}
	for(a=3; sum<100; a++)
	{
		printf("a++");
		for(b=a+1; sum<100; b++)
		{
			c=(int)sqrt(pow(a,2)+pow(b,2));
			if(pow(c,2)==pow(a,2)+pow(b,2) && a+b>c && a+c>b && b+c>a && c<100)
			{
				printf("%d %d %d",a,b,c);
				++i;
			}
		}
	}
	return pHead;
}

/************************
//时间复杂度 O(n)^3,效率太低
PNARR getPyNum()
{
	PNARR pHead = (PNARR)malloc(sizeof(NARR)*SIZE);
	if(NULL == pHead)
	{
		free(pHead);
		printf("分配内存失败");
		exit(-1);
	}
	int i=0;
	int length = SIZE;
	int a=3, b=4, c=5;
	//如何判断内存是否用完？用一个变量i计数
	int sum = pow(a,2)+pow(b,2)+pow(c,2);
	while(sum<=1000)
	{
		while(sum<=1000)
		{
			while(sum<=1000)
			{
				if(pow(a,2)+pow(b,2)==pow(c,2))
				{
					printf("%d %d %d\n",a,b,c);
					if(i<length)
					{
						pHead[i].pynum[0]=a;
						pHead[i].pynum[1]=b;
						pHead[i].pynum[2]=c;
					}
					else
					{
						realloc(pHead, 2*length*sizeof(NARR));
						length *=2;
					}
					++i;
				}
				++c;
			}
			++b;
		}
		++a;
	}
	return pHead;
}*/

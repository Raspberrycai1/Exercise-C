/*
2. 整数处理

题目描述
输入 10 个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。写三个
函数； ①输入 10 个数；②进行处理；③输出 10 个数。
输入
10 个整数
输出
整理后的十个数，每个数后跟一个空格（注意最后一个数后也有空格）
样例输入
2 1 3 4 5 6 7 8 10 9
样例输出
1 2 3 4 5 6 7 8 9 10
*/


# include <stdio.h>
# include <malloc.h>

void Input10(int*);
void ChangePos(int*);
void Print(int*);

int main()
{

	//分配内存空间,存放10个int型数据
	int* pArr = (int*)malloc(sizeof(int)*10);
	printf("输入10个数(空格隔开):\n");
	Input10(pArr);
	ChangePos(pArr);
	Print(pArr);
	return 0;
}

void Input10(int* num10)
{
	//用scanf
	scanf("%d %d %d %d %d %d %d %d %d %d",&num10[0],&num10[1],\
		&num10[2],&num10[3],&num10[4],&num10[5],\
		&num10[6],&num10[7],&num10[8],&num10[9]);
	return;
}

void ChangePos(int* num10)
{
	int i,temp;
	int maxId=0,minId=0;//假定最大最小都是第1个数
	for(i=0;i<10;i++)
	{
		if(num10[i]<num10[minId])
		{
			minId=i;
		}
		else if(num10[i]>num10[maxId])
		{
			maxId=i;
		}
	}
	//找到最大最小之后,换位置
	temp = num10[0];
	num10[0] = num10[minId];
	num10[minId] = temp;
	
	temp =num10[9];
	num10[9]=num10[maxId];
	num10[maxId]=temp;

	return;
}
//输出10个数
void Print(int* num10)
{
	int i;
	printf("结果是：\n");
	for(i=0; i<10; i++)
	{
		printf("%d ", num10[i]);
	}
	printf("\n");
}

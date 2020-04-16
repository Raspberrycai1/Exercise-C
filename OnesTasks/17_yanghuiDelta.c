/* 17.倒杨辉三角
Fans 喜欢图形，而且喜欢把图形倒过来欣赏。有一次，他看见杨辉三角形 了，觉得很新鲜，
于是就把它们大大小小地摆布出来。输入一些整数 n（1≤n≤10），读入其每个整数，以该
整数为行数，其画出来的倒杨辉三角形就是fans 所喜欢欣赏的。Fans 是手工做的，你却可
以用编程更快捷地做出来，多爽啊!
输入
多组数据，每组数据占一行
输出
每个倒杨辉三角参考样例输出，每输出一个后必跟一空行
样例输入
5
3
样例输出
1 4 6 4 1
1 3 3 1
1 2 1
1 1
1
1 2 1
1 1
1
************************/
/*杨辉三角
 * 1. 每个数等于它上方两数之和
 * 2. 每行数字左右对称，由1开始逐渐变大
 * 3. 第n行的数字有n项
 * 4. 前n行共[(1+n)n]/2个数
 * 5. 第n行的m个数可表示为C(n-1,m-1),即为从n-1个不同元素中取m-1个元素的组合数
 * 6. 第n行的第m个数和第n-m+1个数相等
 * 7. 每个数字等于上一行的左右两个数字之和：即第n+1行的第i个数等于第n行的第i-1个数和第i个数之和，可由此写出整个杨辉三角
 *
 * C(5,2)=C(n,k)=5x4/2!
 * C(5,3)=5x4x3/3!
 * C(5,4)=C(5,1)=5/1!
 */
/*
 * 1.读输入(行数)放入一块内存
 * 2.根据行数计算数字，放入内存
 * 3.倒序输出
 */
# include <stdio.h>
# include <malloc.h>

int* getRows(void);
int** calDelta(int *);
void rePrint(int**);

int main(void)
{
	int* pRow = NULL;
	int** adr_of_Arr = NULL;
	
	pRow = getRows();


	return 0;
}

int* getRows(void)
{
	int * pRow = (int*)malloc(sizeof(int)*10);
	int i=0;
	char c;

	while((c=getchar())!='\n')
	{
		scanf("%d",&pRow[i++]);
		char Enter=getchar();
	}

	for(i=0; i<10; i++)
	{
		printf("%d",pRow[i]);
	}

	return pRow;
}

/*16.随机数
明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用 计算机生成
了 N 个 1 到 1000 之间的随机整数（N≤100），对于其中重复的数字，只保留一个，把其
余相同的数去掉，不同的数对应着不同的学生的学号。然 后再把这些数从小到大排序，按
照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
输入
有 2 行，第 1 行为 1 个正整数，表示所生成的随机数的个数：
N
第 2 行有 N 个用空格隔开的正整数，为所产生的随机数。
输出
也是 2 行，第 1 行为 1 个正整数 M，表示不相同的随机数的个数。第 2 行为 M 个用空格隔
开的正整数，为从小到大排好序的不相同的随机数。
样例输入
10
20 40 32 67 40 20 89 300 400 15
样例输出
8
15 20 32 40 67 89 300 40
**************************************/

# include <stdio.h>
# include <stdlib.h>	//srand
# include <time.h>	//time

int * getNnum(int);	//获取输入，并显示原始数据
void sort(int *,int N);	//先排序再查找
void removDupli(int *,int N);	//去重

int main(void)
{
	int * pArr=NULL;
	int N;

	printf("需要输入几个数？len = ");
	scanf("%d",&N);

	pArr = getNnum(N);
	sort(pArr, N);
	removDupli(pArr,N);

	return 0;
}

int * getNnum(int N)
{
	int * pArr = (int*)malloc(sizeof(int)*N);
	int i;
	srand((unsigned)(time(NULL)));

	for(i=0; i<N; i++)
	{
		pArr[i]= rand()%1000+1;
		printf("%d ",pArr[i]);
	}
	
	printf("\n");
	return pArr;
}

void sort(int * pArr, int N)
{
	int i, j, temp;
	

	for(i=0; i<N-1; i++)
		for(j=0; j<N-1-i; j++)
		{
			if(pArr[j]>pArr[j+1])
			{
				temp=pArr[j];
				pArr[j]=pArr[j+1];
				pArr[j+1]=temp;
			}
		}
	return ;
}

void removDupli(int * pArr, int N)
{
	int i, j=0,n=0;
	
	for(i=0; i<N; i++)
	{
		j=i;
		if(pArr[j] == pArr[j+1])
		{
			continue;
		}
		n++;
	}
	printf("%d\n",n);

	//执行第2遍：
	for(i=0; i<N; i++)
	{
		j=i;
		if(pArr[j] == pArr[j+1])
		{
			continue;
		}
		printf("%d ",pArr[i]);
		n++;
	}
	printf("\n");
}

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

/*
输入的数据类型用int，如果用char接收数据，输入10会被拆成1和0
但是怎么读取用户输入的数字呢？
 
获取用户输入的函数一般是：
	scanf()：和 printf() 类似，scanf() 可以输入多种类型的数据。
	getchar()、getche()、getch()：这三个函数都用于输入单个字符。
	gets()：获取一行数据，并作为字符串处理。http://c.biancheng.net/cpp/html/2899.html
*/

# include <stdio.h>
# include <malloc.h>

int* Input10();
int* ChangePos(int*);
void Print(int*);

int main()
{
	int* num10 = (int*)malloc(sizeof(int)*10);
	printf("Please input 10 numbers(seperate with space):\n");
	num10=Input10();
	ChangePos(num10);
	Print(num10);
	return 0;
}

//也可以构造链表，但是我忘了怎么写
int* Input10()
{
	//int i;
	int* num10=(int*)malloc(sizeof(int)*10);
	//用scanf
	scanf("%d %d %d %d %d %d %d %d %d %d",&num10[0],&num10[1],\
		&num10[2],&num10[3],&num10[4],&num10[5],&num10[6],&num10[7],&num10[8],&num10[9]);
	/*
	for(i=0; i<10; i++)
	{
		scanf("%d",&num10[i]);//scanf遇到空格就结束读取
	}*/
	/*for(i=0;i<10;i++)
	{
		num10[i]=(int)getchar();
		if(32 == num10[i])//不要空格
		{
			i=i-1;
		}
	}
	*/
	return num10;
}

int* ChangePos(int* num10)
{
	int i;
	int maxId=0,minId=0;//假定最大最小都是第1个数
	int temp;
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

	return num10;
}
//输出10个数
void Print(int* num10)
{
	int i;
	printf("结果是：\n");
	for(i=0; i<10; i++)
	{
		printf("%c ", num10[i]);
	}
	printf("\n");
}

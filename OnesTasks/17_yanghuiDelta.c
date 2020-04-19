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

1 4 6 4 1
1 3 3 1
1 2 1
1 1
1
1 2 1
1 1
1***********************/
/*杨辉三角
 * 1. 每个数等于它上方两数之和
 * 2. 每行数字左右对称，由1开始逐渐变大
 * 3. 第n行的数字有n项
 * 4. 前n行共[(1+n)n]/2个数
 * 5. 第n行的m个数可表示为C(n-1,m-1),即为从n-1个不同元素中取m-1个元素的组合数
 * 6. 第n行的第m个数和第n-m+1个数相等
 * 7. 每个数字等于上一行的左右两个数字之和：即第n+1行的第i个数等于第n行的第i-1个数和第i个数之和，可由此写出整个杨辉三角
 *
 * C(5,0)= 1
 * C(5,1)= 5/1! = 5
 * C(5,2)= C(n,k)=5x4/2! = 10
 * C(5,3)= 5x4x3/3! = 10
 * C(5,4)= C(5,1)=5/1! = 5
 * C(5,5)= C(5,0)= 1
 */
/*
 * 1.读用户输入(行数)放入一个二维数组
 * 2.根据行数计算数字，放入内存
 * 3.倒序输出:前n行共[(1+n)n]/2个数，倒着取地址打印
 */
# include <stdio.h>
# include <stdlib.h>	//malloc
# include <string.h>	//memset

void output (int);

int main(void)
{
	char c;
	int rows[10]={0}, i=0;

	printf("请输入行数：\n");
	while((c=getchar())!='\n')
	{
		ungetc(c,stdin);//把c返回输入流
		scanf("%d",&rows[i++]);
		scanf("%*c");	//吸收回车
	}

	//输出：
	for(i=0; i<10; i++)
	{
		output(rows[i]);
	}
	
	return 0;
}

void output(int N)
{
	if(0 == N)
	{
		return;
	}
	//定义行首地址/指针数组
	int* * prows = (int* *)malloc(sizeof(int*)*N);
	//定义每行内存空间
	for(int n=0; n<N; n++)
	{
		prows[n] = (int *)malloc(sizeof(int)*(n+1));
	}
	
	//正杨辉三角赋值
	int address =0;
	for(int i=0; i<N; i++)//3,2,1
	{
		address += i;
		*((int*)prows+address) = 1; //每行第一个数=1
		
		//计算第1个后面的数
		for(int j=1; j<=i; j++)
		{
			//分子
			int product = 1; //积
			int decrease = i; //每次减1
			for(int k=1; k<=j; k++)//分子有几个数相乘
			{
				product *= decrease--;
			}
			//分母
			int factorial = 1;//阶乘
			for(int lessen=j; lessen>0; lessen--)
			{
				factorial *= lessen;
			}
			*((int*)prows+address+j)=product/factorial;
		}
	}
	/*//printf("输出查看二维数组\n");
	address = 0;
	for(int i=0; i<N; i++)
	{
		//printf("第%d行:\n",i);
		address += i;
		for(int j=0; j<=i; j++)
		{
			printf("%d ",*((int*)prows+address+j));
			//printf("prows[%d][%d]=%d\n",i,j,*((int*)prows+adress+j));
		}
		printf("\n");
	}*/

	//把prows反序输出
	//printf("反序输出:\n");
	int spacenum=1;
	for(int address=((N+1)*N)/2-1; address>=0; address--)//address初值是最后一个元素的偏移量,基地址是prows
	{
		//printf("第%d行：\n",N);
		//printf("address=%d\n",address);
		printf("%d ",*((int*)prows+address));
		
		if(address+N == ((N+1)*N)/2) //第N行有N个数，address减完N之后，代表读完第N行，输出换行
		{
			printf("\n");
			N = N-1;
			//输出空格
			for(int s=1; s<=spacenum; s++)
			{
				printf(" ");
			}
			spacenum++;
		}
	}
	printf("\n");
}
	


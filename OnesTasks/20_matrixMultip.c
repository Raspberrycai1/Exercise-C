/*20.矩阵相乘 题目描述
小明最近在为线性代数而头疼，线性代数确实很抽象（也很无聊），可惜他的老师正在讲这 矩阵乘法这一段内容。 当然，小明上课打瞌睡也没问题，但线性代数的习题可是很可怕的。 小明希望你来帮他完成这个任务。
现在给你一个 ai 行 aj 列的矩阵和一个 bi 行 bj 列的矩阵， 要你求出他们相乘的积（当然也是矩阵）。 (输入数据保证 aj=bi,不需要判断)
输入
输入文件共有 ai+bi+2 行，并且输入的所有数为整数（long long 范围内）。 第 1 行：ai 和 aj 第 2~ai+2 行：矩阵 a 的所有元素 第 ai+3 行：bi 和 bj 第 ai+3~ai+bi+3 行：矩阵 b 的所有元素
输出
输出矩阵 a 和矩阵 b 的积（矩阵 c) （ai 行 bj 列）
样例输入
2 2
12 23
45 56
2 2
78 89
45 56
样例输出
1971 2356
6030 7141
*******************/
//12*78+23*45	12*89+23*56
//45*78+56*45	45*89+56*56
//
//左矩阵是按行存取，右矩阵按列存取，分别有输入函数读取
//左矩阵的行乘右矩阵的列

# include <stdio.h>
# include <stdlib.h>	//malloc

/*=============函数声明==============*/
int ** get2DArrayLeft(int,int); //返回一个指针数组：每一行第一个元素第一个字节的指针，
		     //数组"元素"是一个一维数组，所以(指针数组)里的每个指针指向的是一个“数组名”（int*类型)
int ** get2DArrayRight(int, int);
void mutiply(int **, int **, int **);

int main(void)
{
	int row, column;
	int ** arr1;
	int ** arr2;
	int ** matrixInfo = (int **)malloc(sizeof(int*)*2); //记录2个矩阵的行数列数
	for(int i=0; i<2; i++) //2个矩阵对应2行，每行有2个数：行数和列数
	{
		matrixInfo[i]=(int *)malloc(sizeof(int)*2);
	}

	printf("行 列：");
	scanf("%d %d",&row,&column);
	matrixInfo[0][0]=row;
	matrixInfo[0][1]=column;
	arr1 = get2DArrayLeft(row, column);
	
	printf("行 列：");
	scanf("%d %d",&row,&column);
	matrixInfo[1][0]=row;
	matrixInfo[1][1]=column;
	arr2 = get2DArrayRight(row, column);
	
	mutiply(arr1, arr2, matrixInfo);
	
	return 0;
}

int ** get2DArrayLeft(int row, int column)
{
	//定义各行行首指针
	int ** prows;//指针数组：指向每一行第一个元素
	prows = (int **)malloc(row*sizeof(int *));
	
	//分配各行内存空间：每一行有column个数
	for(int i=0; i<row; i++)
	{
		prows[i] = (int *)malloc(column*sizeof(int));
	}
	
	//接收用户输入：
	for(int i=0; i<row;i++)
	{
		printf("请输入第%d行：",i+1);
		for(int j=0; j<column; j++)
		{
			scanf("%d",(int *)prows+i*column+j);//空格和回车都可以结束scanf输入,这是只想单个输入，所以%d后不能跟"空格",否则结束不了
		}
	}

	/*//输出查看：
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			printf("%d ",*((int *)prows+i*column+j));
		}
		printf("\n");
	} */
	return prows;
}
int ** get2DArrayRight(int row, int column)
{
	int ** pcolumns;//指针数组：指向每一列第一个元素
	pcolumns = (int **)malloc(column*sizeof(int *));
	
	//分配各列内存空间：每一列有row个数
	for(int i=0; i<column; i++)
	{
		pcolumns[i] = (int *)malloc(row*sizeof(int));
	}
	
	//接收用户输入是按行：
	for(int i=0; i<row;i++)
	{
		printf("请输入第%d行：",i+1);
		for(int j=0; j<column; j++)
		{
			scanf("%d",(int *)pcolumns+j*row+i);
		}
	}

	//输出查看：
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
		{
			printf("%d ",*((int *)pcolumns+j*row+i));
		}
		printf("\n");
	} 
	return pcolumns;
}


void mutiply(int ** arr1, int ** arr2, int ** matrixInfo)
{
	//结果矩阵有：arr1的行数和arr2的列数
	int ** result = (int* *)malloc(sizeof(int*)*matrixInfo[0][0]);
	for(int i=0; i<matrixInfo[0][0]; i++)
	{
		result[i] = (int *)malloc(sizeof(int)*matrixInfo[1][1]);
	}

	for(int i=0; i<matrixInfo[0][0]; i++)
	{
		//计算每一行
		for(int j=0; j<matrixInfo[1][1]; j++)
		{
			//计算每一个
			int sum=0;
			for(int k=0; k<matrixInfo[0][1]; k++)
			{
				sum+=*((int*)arr1+i*matrixInfo[0][1]+k) * *((int*)arr2+j*matrixInfo[1][0]+k);
			}
			printf("%d ",sum);
		}
		printf("\n");
	}
}


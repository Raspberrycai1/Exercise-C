/*4. 成绩统计--用结构体数组
题目描述
有 N 个学生，每个学生的数据包括学号、姓名、3 门课的成绩，从键盘输入 N 个学生的数据，要求打印出 3 门课的总平均成绩，以及最高分的学生的数据（包括学号、姓名、3 门课成绩）
输入
学生数量N 占一行;每个学生的学号、姓名、三科成绩占一行，空格分开。
输出
各门课的平均成绩 最高分的学生的数据(包括学号、姓名、3 门课成绩）
样例输入
2
1 blue 90 80 70
b clan 80 70 60
样例输出
85 75 65
1 blue 90 80 70
************************/

# include <stdio.h>
# include <malloc.h>

typedef struct Student
{
	int sid;
	char name[20];
	int score[3];
}STU,*PSTU;

void getInput(PSTU,int);
void calcAvg(PSTU,int);
void printTotalMax(PSTU,int);

int main()
{
	int N;
	printf("请输入学生个数：\n");
	scanf("%d", &N);
	PSTU pArr = (PSTU)malloc(sizeof(STU)*N);
	getInput(pArr,N);
	calcAvg(pArr,N);
	printTotalMax(pArr,N);

	return 0;
}

void getInput(PSTU pArr,int N)
{
	int i;	
	
	for(i=0; i<N; i++)
	{		
		printf("请输入第%d个学生的学号,姓名和3门成绩:",i+1);
		scanf("%d %s %d %d %d",&pArr[i].sid,pArr[i].name,&pArr[i].score[0],&pArr[i].score[1],&pArr[i].score[2]);
	}
}
//计算并打印三科平均分
void calcAvg(PSTU pArr,int N)
{
	int i, j, sum=0;
	float avg;
	printf("三科平均分：");
	for(i=0; i<3; ++i)
	{
		sum = 0;
		for(j=0; j<N; ++j)
		{
			sum+=pArr[j].score[i];
		}
		avg = sum/N;
		printf("%1.f ",avg);
	}
	printf("\n");
}

//打印分数最高的同学信息
void printTotalMax(PSTU pArr, int N)
{
	int i,j;
	int sumJ,sumJ_1;
	STU temp;

	printf("分数最高的同学：\n");
	//冒泡按score升序，输出最后一个
	for(i=0; i<N-1; ++i)
	{
		for(j=0; j<N-1-i; ++j)
		{
			sumJ=pArr[j].score[0]+pArr[j].score[1]+pArr[j].score[2];
			sumJ_1=pArr[j].score[0]+pArr[j].score[1]+pArr[j].score[2];
			if(sumJ > sumJ_1)// >升序 <降序
			{
				temp = pArr[j];
				pArr[j] = pArr[j+1];
				pArr[j+1] = temp;
			}
		}
	}
	printf("%d %s %d %d %d\n",pArr[N-1].sid,pArr[N-1].name,pArr[N-1].score[0],pArr[N-1].score[1],pArr[N-1].score[2]);
}

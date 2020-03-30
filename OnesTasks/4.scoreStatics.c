/*4. 成绩统计
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
# include <string.h>
# include <malloc.h>

typedef struct Student
{
	int sid;
	char name[20];
	int score[3];
}STU,*PSTU;

void getInput(PSTU);
void calcAvg(PSTU);
void printTotalMax(PSTU);

int main()
{
	PSTU pHead = (PSTU)malloc(sizeof(STU));
	getInput(pHead);
	calcAvg(pHead);
	printTotalMax(pHead);

	return 0;
}

void getInput(PSTU pHead)
{
	int N; //学生数量
	int sid;
	char* name[20];
	int s1,s2,s3;
	int i;
	printf("请输入学生数量");
	scanf("%d",&N);

	for(i=0; i<N; i++)
	{
		PSTU pNew = (PSTU)malloc(sizeof(STU));
		
		printf("请输入第%d个学生的学号,姓名和3门成绩",i+1);
		scanf("%d %s %d %d %d",&sid,name[20],&s1,&s2,&s3);

		pNew->sid = i+1;
		//pNew->name = name; //array type is not assignable
		strcpy(*pNew->name,name[20]);
	}
}

/* 郝斌C语言 164_结构体11_综合应用_学生管理系统
动态构造存放学生信息的结构体数组，然后按分数排序输出
********/

# include <stdio.h>
# include <malloc.h>

struct Student
{
	int age;
	float score;
	char name[100];	
};
int main(void)
{
	int len;
	struct Student * pArr;
	int i,j;
	struct Student t;

	//动态的构造一维数组
	printf("请输入学生的个数:\n");
	printf("len = ");
	scanf("%d",&len);
	
	//分配了一块连续的内存？每一个元素是struct Student类型
	pArr = (struct Student *)malloc(sizeof(struct Student)*len);
	//pArr是这个结构体数组的名字/; pArr[0]是第一个元素 
	
	for (i=0; i<len; i++)
	{
		printf("请输入第%d个学生的信息：",i+1);
		printf("age=");
		scanf("%d", &pArr[i].age);

		printf("name= ");
		scanf("%s", pArr[i].name); //name是数组名，本身就已经是数组首元素的地址，所以pArr[i].name不用取地址
		//getchar();//作用可能是吸收回车,但是加不加效果一样

		printf("score= ");
		scanf("%f", &pArr[i].score);
	}

	//按学生成绩升序排序，冒泡算法
	for(i=0; i<len-1; ++i)
	{
		for(j=0; j<len-1-i; ++j)
		{
			if(pArr[j].score > pArr[j+1].score)
			{
				t = pArr[j]; //两个变量整体对换(位置)
				pArr[j] = pArr[j+1];
				pArr[j+1] = t;
			}
		}
	}
	//输出
	printf("\n\n学生信息是：\n");
	for(i=0; i<len; ++i)
	{
		printf("第%d个学生的信息是：\n", i+1);
		printf("age = %d\n", pArr[i].age);
		printf("name = %s\n", pArr[i].name);//按%s输出,跟的是数组地址
		printf("score = %1.f\n", pArr[i].score);
		
		printf("\n");
	}

	
	return 0;
}

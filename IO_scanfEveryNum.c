# include <stdio.h>
# include <stdlib.h>

# define LEN 10
int* pNum = (int*)malloc(sizeof(int)*10);
int* temp = NULL;

int i=0;
int length=10;
char c;
int main(void)
{
	printf("输入数字：\n");
	//while((c=getchar())!='\n')
	while(scanf("%d",&pNum[i++]))
	{
		//printf("c=%c\n",c);
		//ungetc(c,stdin); //将c送回输入流
		//scanf("%d", &pNum[i++]);
		printf("pNum[i-1]=%d\n",pNum[i-1]);
		
		if(i > length)
		{
			//printf("执行到内存扩容");
			length *= 2;
			temp = (int*)realloc(pNum,sizeof(int)*length);//realloc前面要加(int*)
			//否则编译出错error: invalid convertion from 'void*' to 'int*'
			//C语言编译器允许隐含性的将一个通用指针转换为任意类型的指针，而C＋＋不允许的。
			if(temp == NULL)
			{
				printf("realloc分配内存失败！pNum仍指向原始内存");
				exit(-1);
			}
			pNum = temp;
		}
	}

	printf("输出:\n");
	for(i=0; i<10; i++)
	{
		printf("%d",pNum[i]);
	}

	return 0;
}

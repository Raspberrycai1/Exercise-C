//表达式不能作为for循环条件
# include <stdio.h>
# include <stdlib.h>
# include <string.h> //memset
# include <math.h>

typedef struct list_3
{
	int abc[3];
}ABC, *PABC;

PABC getABC();
PABC changePos();
void traverse(PABC);

int main(void)
{
	PABC pHead;
	printf("start:\n");
	pHead = getABC();
	printf("end!\n");

	return 0;
}

PABC getABC()
{
	int count=0;
	int a=3,b=4,c=5;
	int sum=a+b+c;
	int len=10;

	PABC pHead = (PABC)malloc(sizeof(ABC)*len);
	if(NULL == pHead)
	{
		printf("内存分配失败");
	}
	
	for(a=3; a<1000; a++)
	{
		for(b=a+1; b<1000; b++)
		{
			c=(int)sqrt(a*a+b*b);
			sum = a+b+c; //sum虽然是个表达式，但是使用sum时不会跳转到定义处再计算一遍，用=赋值给他才会改变
			if(c*c==a*a+b*b && a+b>c && a+c>b && b+c>a )
			{
				if(sum>1000)
					return pHead;
				printf("%4d %4d %4d,sum=%4d     ",a,b,c,sum);
				count++;
				pHead[count].abc[0]=a;
				pHead[count].abc[1]=b;
				pHead[count].abc[2]=c;

				if(count>=len)
				{
					PABC pHead=(PABC)realloc(pHead, 2*len*sizeof(ABC));
            				memset(pHead+len, 0, len * sizeof(ABC));
					len*=2;
				}
				if(count%4 == 0)
					printf("\n");
			}
		}
	}
	return pHead;
}

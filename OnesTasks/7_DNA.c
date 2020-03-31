/*题目描述
小强从小就喜欢生命科学，他总是好奇花草鸟兽从哪里来的。终于， 小强上中学了，接触
到了神圣的名词--DNA.它有一个双螺旋的结构。这让一根筋的小强抓破头皮，“要是能画
出来就好了” 小强喊道。现在就请你帮助他吧
输入
输入包含多组测试数据。第一个整数 N（N<=15）,N 表示组数，每组数据包含两个整数
a,b。a表示一个单位的DNA串的行数，a为奇数且 3<=a<=39。b表示重复度(1<=b<=20)。
输出
输出 DNA 的形状，每组输出间有一空行。
样例输入
2
3 1
5 4
样例输出
X X
 X
X X

X   X
 X X
  X
 X X
X   X
 X X
  X
 X X
X   X
 X X
  X
 X X
X   X
 X X
  X
 X X
X   X
************************/
/******
1.第1行0个空格
第2行1个空格
第3行2个空格
第1+a/2行,有a/2个空格

X     X
 X   X 
  X X 
   X
  X X
 X   X

以这个为单位，如果是最后一个图形，就补上最后一行X   X

每一行是一个字符串（puts()）
 ********/
# include <stdio.h>
# include <malloc.h>

typedef struct a_b
{
	int couple[2];
}AB, *PAB;

void output(int,int);

int main(void)
{
	int i, couple;
	int a,b;
	printf("几组？");
	scanf("%d", &couple);
	PAB pHead = (PAB)malloc(sizeof(AB)*couple);
	for(i=0; i<couple; i++)
	{
		printf("a=? b=? ");
		scanf("%d %d",&a,&b);
		pHead[i].couple[0]=a;
		pHead[i].couple[1]=b;
	}
	for(i=0; i<couple; i++)
	{
		output(pHead[i].couple[0],pHead[i].couple[1]);
		printf("\n");
	}
	return 0;
}

void output(int a, int b)
{
	int i,j,k;
	int len;
	
	for(i=b;i>0; i--)//重复次数
	{
		for(j=0; j<=a/2; j++)//行数：前一半
		{
			//输出空格1-2-3-4-5
			for(k=0; k<j; k++)
			{
				printf(" ");
			}
			//输出一个X
			printf("X");
			//输出空格：5-3-1
			for(k=0; k<a-2*(j+1); k++)
			{
				printf(" ");
			}
			//不在横对称轴上就打印X 
			if(j != a/2)
			{
				printf("X");
			}
			printf("\n");
		}
		//输出后一半
		len=1;
		for(j=a/2-1; j>0; j--)//j=2,1(,0)
		{
			//输出空格 
			for(k=0; k<j; k++)//k=0,1(,2)
			{
				printf(" ");
			}
			printf("X");
			//输出空格
			for(k=0; k<len; k++)
			{
				printf(" ");
			}
			len+=2;
			//不在横对称轴上就打印X 
			if(j != a/2)
			{
				printf("X");
			}
			printf("\n");
		}
		if(i==1)//在最后一次补上最后一行
		{
			printf("X");
			for(k=0; k<a-2; k++)
			{
				printf(" ");
			}
			printf("X");
		}
	}
	printf("\n");
}


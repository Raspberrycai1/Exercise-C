/* 
1 2 3 4 5
scanf把1读入存入数组中，getchar把空格输入，以此往后遍历
所以我们只需判断getchar()得到的是否是'\n'即可
*/

# include <stdio.h>
# include <malloc.h>

int main(void)
{
	int i,n;
	int cur;
	printf("几个数？：");
	scanf("%d",&n);
	int* pHead = (int*)malloc(sizeof(int)*n);

	for(i=0; i<n; i++)
	{
		scanf("%d",&cur);
		pHead[i]=cur;
		char c = getchar();
		if(c=='\n')
		{
			break;
		}
	}
	//输出
	for(i=0; i<n; i++)
	{
		printf("%d",pHead[i]);
	}
	return 0;
}


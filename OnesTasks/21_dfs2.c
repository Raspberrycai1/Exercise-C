# include <stdio.h>

int N;
int m=3; //连放3个爆炸
int ans=0;

int dfs(int i, int j)
{
	if(j==m)//如果有连续的3坑都有物质，此方案不行
	{
		return 0;
	}
	if(i==N)
	{
		ans++;//能到n,说明之前没有连续的3坑，此方案可行
		return 1;
	}

	int ans = 0;
	dfs(i+1, 0);//第i+1个坑里没有物质，之后的坑里是否放物质与前面没有联系了
	dfs(i+1, j+1);//前i+1个坑中最后连续j+1个坑里都有物质
}

int main()
{
	int res, n=0;
	int input[10]={0};
	char c;
	while((c=getchar())!='\n')
	{
		ungetc(c,stdin);
		scanf("%d",&input[n++]);
		scanf("%*c");
	}
	for(n=0; n<10; n++)
	{
		if(input[n]==0)
		{
			break;
		}
		N=input[n];
		dfs(0,0);//从第0个坑里开始放
		printf("%d\n",ans);
		ans = 0;
	}
	//scanf("%d",&N);
}

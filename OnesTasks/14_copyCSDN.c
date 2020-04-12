#include <stdio.h>
#include <string.h>
#define INF 1<<30

char map[105][105];
int dir[4][2] = {-1,0,0,1,1,0,0,-1};
int n;
int vis[105][105];
int min=INF;
int f_x,f_y;
void dfs(int x,int y,int t,char ch) 
{
	if(x<=0 || x>n || y<=0 || y>n)
		return ;
	if(x==f_x && y==f_y)
	{
		if(t<min)
			min=t;
		return ;
	}
	for(int k=0;k<4;k++)
	{
		int px=x+dir[k][0],py=y+dir[k][1];
		if(!vis[px][py] && map[px][py]!=ch)
		{
			vis[px][py]=1;
			dfs(px,py,t+1,map[px][py]);
			vis[px][py]=0;
		}
	}
}
 
int main()
{
	int i,j;
	int s_x,s_y;
	memset(map,0,sizeof(map));
	memset(vis,0,sizeof(vis));
	printf("行数:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%*c%c",map[i]+j);
			if(map[i][j]=='A')
			{//开始点 
				s_x=i;
				s_y=j;
			}
			else if(map[i][j]=='B')
			{//终止点 
				f_x=i;
				f_y=j;
			}
		}
	}
	vis[s_x][s_y]=1;
	dfs(s_x,s_y,0,map[s_x][s_y]);
	if(min==INF)
		printf("-1");
	else
		printf("%d\n",min);
	return 0;
}

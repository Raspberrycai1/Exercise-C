#include<stdio.h>

int n,m,ans=0;

int dfs(int i,int j){
    if(j==m) return 0;//如果有连续的m坑都有物质，此方案不行 
    if(i==n) {
       ans++;//能到n,说明之前没有连续的m坑都有物质，此方案可以
       return 1;
    } 
    int ans=0;
    dfs(i+1,0);//第i+1个坑里没有物质，之后的坑里是否放物质与前面没有联系了 
    dfs(i+1,j+1);//前i+1个坑中最后连续j+1个坑里都有物质， 
}
int main(){
    int res;
    scanf("%d%d",&n,&m);
    dfs(0,0);//从第0个坑里开始放 
    printf("%d",ans); 
} 

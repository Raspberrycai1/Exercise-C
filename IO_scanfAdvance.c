//scanf高级用法

/*
#include<stdio.h>
int arr[10];
char c;
int i;
int n;

int main(){
while(scanf("%d",&n)!=EOF && (n>=1&&n<=10))
{
	arr[i++]=n;

}
printf("输出:\n");

for(i=0; i<10; i++)
{
	printf("%d",arr[i]);
}

return 0;

}*/
#include<stdio.h>  
int main()  
{  
    int n,a[10][10]={0},i,j,k;  //二维数组存基本杨辉三角
    while (scanf("%d",&n)!=EOF&&(n>=1&&n<=10))  
    {  
        for(i=0;i<n;i++)  //先往数组里存杨辉三角的基本样子
        {  
            for(j=0;j<=i;j++)  
            {  
                if(i==j||j==0)     //杨辉三角的规律：当行与列相等时或者列为0的时候，为1
                    a[i][j]=1;  
                else  
                    a[i][j]=a[i-1][j]+a[i-1][j-1];  //其他时候是前面的两个相加即可
            }  
             
        }  
        for(i=0;i<n;i++)  //按要求输出杨辉三角
        {  
            for(j=0;j<i;j++)  
                printf("   ");  //输出行两个占位符的间隔是3，为了避免bong输出数字就直接用3个空格去代替
            for(k=0;k<n-i;k++){  //倒着输出
                printf("%3d",a[n-i-1][k]); //占位符为3  
                printf("   ");  //后面接着来间隔，方便下一个如果有数，就输出，没数，就输出3个空格
            }  
            printf("\n");  
        }  
        printf("\n");  
    }  
     
    return 0;  
}

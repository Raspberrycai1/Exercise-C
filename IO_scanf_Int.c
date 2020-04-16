//scanf读取一个用空格分隔的 任意位数的整数(int)
//http://blog.sina.com.cn/s/blog_cfb724900102wug8.html

# include <stdio.h>
# include <ctype.h>//isdigit
# include <stdlib.h>//malloc

int main(void)
{
	int a[100];
	char c;
	int i=0;
	int n=0;
	
	printf("请输入:");
	while((c=getchar())!=' ')//getchar从输入流中读取一个字符
	{
		if(isdigit(c))//检查参数是否为十进制数
		{
			ungetc(c,stdin);//将c送回输入流
			scanf("%d",&a[n++]);
		}
	}
	//输出
	printf("输出:\n");
	for(i=0; i<n; i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}

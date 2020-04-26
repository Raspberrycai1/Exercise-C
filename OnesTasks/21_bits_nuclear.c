/*问题分析
根据题目的意思，对于每一个坑位，只有两种情况：放了核物质（记为1），没放核物质（记为0），所以题目的意思就是，在n个坑位中放核物质，满足条件 不存在三个相邻核物质 ，总共有多少种情况。

基本思路
题目中明确规定N<=40，所以计算数据不会太大，可以考虑穷举的方法。
也就是说，总共n个坑，每个坑根据放不放核物质有两种情况，所以总共有 2的n次方种情况，不妨对每种情况都进行一次判断，看看是否发生爆炸（三个1相连）。

比如说9个坑位，如果把这9个坑当做9位2进制数，就好解决了，总共有 pow(2,9) 种情况，最小的数是 000000000 ，最大的数是 111111111。也就是这9位2进制数，对应10进制数的取值范围为 [0，pow(2,9))，不妨对每个10进制数都转换成2进制，然后再遍历这个2进制数，看看是否可能爆炸。
————————————————
版权声明：本文为CSDN博主「smile-yan」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/smileyan9/article/details/101099304
********/
//#include <iostream>
//#include <cmath>
//using namespace std;

# include <stdio.h>
# include <math.h>
# include <stdbool.h>
/**
 * 进制转换函数，从十进制转换成some进制
 */
long long some(long long x, int some)
{
    int ary[50];
    int i=0;
    for(; x != 0; i++)
    {
        ary[i] = x%some;
        x /= some;
    }

    long y=0;
    for(i--; i>=0; i--)
    {
        y *= 10;
        y += ary[i];
    }
    return y;
}

/**
 * 判断是否有三个1相连，表示是否会爆炸
 */
bool get(long long x)
{
    int count = 0;
    while(x)
    {
        int temp = x%10;
        if(temp == 1)
        {
            count++;
            if(count == 3)  return true;
        }
        else
        {
            count=0;
        }
        x /= 10;
    }
    return false;
}

/*/ written by Smileyan 欢迎关注
int main()
{
    int n,i;
    while(cin>>n)
    {
        int count = 0;
        for(i=1; i<=pow(2,n); i++)
        {
            if(get(some(i,2))==true) {
             //   cout<<i<<"  "<<some(i,2)<<endl;
                count++;
            }
        }
        cout<<pow(2,n)-count<<endl;
    }
************************************************/
int main(void)
{
	char c;
	int input[10];
	int i=0;
	while((c=getchar())!='\n')//获取用户输入
	{
		ungetc(c,stdin);
		scanf("%d", &input[i++]);
		scanf("%*c");
	}

	for(int j=0; j<i; j++)//对每一个输入计数
	{
		//countPlans(input[j]);
		int count = 0;
		for(i=1; i<=pow(2,j); i++)
		{
			if(get(some(i,2)) == true)
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
    return 0;
}

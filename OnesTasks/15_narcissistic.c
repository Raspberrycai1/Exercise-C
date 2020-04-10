/*15.水仙花数 
判断一个数是否为"水仙花数"，所谓"水仙花数"是指这样的一个数：首先是一个三位数，
其次，其各位数字的立方和等于该数本身。例如：371 是一个"水仙花数"，
371=3^3+7^3+1^3.
输入
一个三位数
输出
1 或者 0(1 代表此数为水仙花数,0 代表此数不是水仙花数)
样例输入
371
样例输出
1
*******************/
# include <stdio.h>

int main(void)
{
	int num, _num, bit, sum=0;

	printf("请输入数字：");
	scanf("%d",&num);
	_num = num; //num在下面会变化，所以另存一个

	while(0 != num)
	{
		bit = num%10;
		num /= 10;

		sum += bit*bit*bit;
	}

	if(sum == _num)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");

	}
}

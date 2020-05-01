/*29 高精度加法

输入两个整数a和b，输出这两个整数的和。a和b都不超过100位。 

算法描述 

由于a和b都比较大，所以不能直接使用语言中的标准数据类型来存储。对于这种问题，一般使用数组来处理。 

定义一个数组A，A[0]用于存储a的个位，A[1]用于存储a的十位，依此类推。同样可以用一个数组B来存储b。 

计算c  =  a  +  b的时候，首先将A[0]与B[0]相加，如果有进位产生，则把进位（即和的十位数）存入r，把和的个位数存入C[0]，即C[0]等于(A[0]+B[0])%10。然后计算A[1]与B[1]相加，这时还应将低位进上来的值r也加起来，即C[1]应该是A[1]、B[1]和r三个数的和．如果又有进位产生，则仍可将新的进位存入到r中，和的个位存到C[1]中。依此类推，即可求出C的所有位。 

最后将C输出即可。 

输入

输入包括两行，第一行为一个非负整数a，第二行为一个非负整数b。两个整数都不超过100位，两数的最高位都不是0。 

输出

输出一行，表示a  +  b的值。 

样例输入

20100122201001221234567890

2010012220100122

样例输出

20100122203011233454668012
*************/
//用两个数组接收输入
//用循环加
//num[-1],[-2]....也是0。。。

# include <stdio.h>

int convert(char);//把字符换成数字

int main(void)
{
	char num1[100]={0};	//被加数
	char num2[100]={0};	//加数
	char num3[100]={0};	//和
	int i=0, j=0, n=0;	//位索引
	int carry=0;		//进位

	while('\n'!=(num1[i]=getchar()))//输入num1
	{
		num1[i]=convert(num1[i]);
		i++;
	}
	while('\n'!=(num2[j]=getchar()))//输入num2
	{
		num2[j]=convert(num2[j]);
		j++;
	}
	//逐位相加
	i--;
	j--;
	while(i>=0 || j>=0)//i或j还没到0,就继续加
	{
		//printf("num1[%d]=%d, num2[%d]=%d\n",i,num1[i],j,num2[j]);
		
		int sum=0;	//本位和
		sum = num1[i--]+num2[j--]+carry;//第一次carry=0
		
		if(sum>9)	//有进位
		{
			carry = 1;
			sum %= 10;
		}
		else		//无进位
		{
			carry=0;
		}
		num3[n++]=sum;	//从第一位开始赋值
		
		//printf("sum=%d, carry=%d\n",sum, carry);
	}
	//num3[n]=carry;
	//输出查看
	printf("+——————————————————\n");
	//最高位单独打印：
	if(carry !=0)//carry不是0就是1, 是0不打印
		printf("%d",carry);
	for(int k=n-1; k>=0; k--)
	{
		printf("%d",num3[k]);
	}
	printf("\n");
}
int convert(char num)
{
	switch(num)	//对c做判断，并给内存赋值
	{
		case 48 : num=0;break;
		case 49 : num=1;break;
		case 50 : num=2;break;
		case 51 : num=3;break;
		case 52 : num=4;break;
		case 53 : num=5;break;
		case 54 : num=6;break;
		case 55 : num=7;break;
		case 56 : num=8;break;
		case 57 : num=9;break;
	}
	return num;
}

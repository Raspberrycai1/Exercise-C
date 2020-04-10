/*11数字黑洞
任意一个四位数，只要它们各个位上的数字是不全相同的，就有这样的规律：
1)将组成该四位数的四个数字由大到小排列，形成由这四个数字构成的最大的四位数；
2)将组成该四位数的四个数字由小到大排列，形成由这四个数字构成的最小的四位数(如果
四个数中含有 0，则得到的数不足四位)；
3)求两个数的差，得到一个新的四位数(高位零保留)。
重复以上过程，最后一定会得到的结果是 6174。
比如：4312 3087 8352 6174，经过三次变换，得到 6174
输入
一个四位整数，输入保证四位数字不全相同
输出
一个整数，表示这个数字经过多少次变换能得到 6174
样例输入
4312
样例输出
3
*******************/
/* 1.输入一个4位数
 * 2.最大排列
 * 3.最小排列
 * 4.做差得到新数
 */
# include <stdio.h>
# include <stdlib.h>

# define N 4		//4位数

/*******函数声明*********/
void get4nums(int *);	//输入四位数并将每一位单独放入内存
void maxchange(int *);	//4个数字排序，并且加起来变成"1个数"
void subtract(int *);	//“变成”最小数，然后让max-min
int equal(int *);	//判断是否相等，返回标志位NE


int main(void)
{
	int NE=1;	//not equal标志位
	int times=0;	//记录变换次数，最后输出
	int* num_4 = (int*)malloc(sizeof(int)*N); //4位数分开存

	get4nums(num_4);	//获取输入

	while(NE==1) 	//若不等于6174就循环
	{
		++times;
		maxchange(num_4);
		subtract(num_4);
		NE = equal(num_4); //判断是否等于6174
	}

	printf("%d\n",times);
	return 0;
}

void get4nums(int* num_4)
{
	int i;		//4次
	char c;		//每一位按字符接受：getchar()
	int  RE=1;	//输入0的标志位：redo
	
	printf("请输入一个4位数(0不算数)：");
	
	while(1 == RE)	//检测到0就重输
	{
		for(i=0; i<N; i++)	//循环4次
		{
			c=getchar();

			switch(c)	//对c做判断，并给内存赋值
			{
				case 48 : printf("您输入了0,请重新输入:"); RE = 1; break;
				case 49 : num_4[i]=1;break;
				case 50 : num_4[i]=2;break;
				case 51 : num_4[i]=3;break;
				case 52 : num_4[i]=4;break;
				case 53 : num_4[i]=5;break;
				case 54 : num_4[i]=6;break;
				case 55 : num_4[i]=7;break;
				case 56 : num_4[i]=8;break;
				case 57 : num_4[i]=9;break;
			}
			RE = 0;
		}
	}
}

void maxchange(int* num_4)
{
	int i, j, temp;
	
	//冒泡排序
	for(i=0; i<N-1; i++)
		for(j=0; j<N-1-i; j++)
		{
			if(num_4[j]<num_4[j+1])
			{
				temp = num_4[j];
				num_4[j] = num_4[j+1];
				num_4[j+1] = temp;
			}
		}
}

void subtract(int * num_4)
{
	int i, j, temp;
	int maxnum=0, minnum=0, differ;
	int* _num =(int*)malloc(sizeof(int)*4);

	//复制
	for(i=0; i<N; i++)
	{
		_num[i]=num_4[i];
	}

	//重组最小值
	for(i=0; i<N-1; i++)
		for(j=0; j<N-1-i; j++)
		{
			if(_num[j] > _num[j+1])
			{
				temp = _num[j];
				_num[j] = _num[j+1];
				_num[j+1] = temp;
			}
		}

	//把数组变成1个数字：每一位加权和
	for(i=0; i<N; i++)
	{
		maxnum+=num_4[i];
		maxnum*=10;
	}
	maxnum/=10; //上面把最后的个位也乘了10，所以这里除掉
	
	//把“最小值数组”变成1个数字：加权和
	for(i=0; i<N; i++)
	{
		minnum+=_num[i];
		minnum*=10;
	}
	minnum/=10;

	//相减
	differ=maxnum-minnum;
	
	//逐位再次放入内存
	for(i=N-1; i>=0; i--)
	{
		num_4[i]=differ%10;
		differ/=10;
	}
}

int equal(int* num_4)
{	
	int NE=1;
	int i;
	int arr[4]={6,1,7,4};

	//逐位比较：
	for(i=0; i<N; i++)
	{
		if(num_4[i] != arr[i])
		{
			NE = 1;
			break;
		}
		else
		{
			NE=0;
		}
	}
	return NE;
}

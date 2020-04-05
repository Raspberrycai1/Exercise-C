/*9数字游戏
栋栋正在和同学们玩一个数字游戏。
游戏的规则是这样的：栋栋和同学们一共 n 个人围坐在一圈。栋栋首先说出数字 1。接下来，
坐在栋栋左手边的同学要说下一个数字 2。再下面的一个同学要从上一个同学说的数字往下
数两个数说出来，也就是说 4。下一个同学要往下数三个数，说 7。依次类推。
为了使数字不至于太大，栋栋和同学们约定，当在心中数到 k-1 时，下一个数字从 0 开
始数。例如，当 k=13 时，栋栋和同学们报出的前几个数依次为：
1, 2, 4, 7, 11, 3, 9, 3, 11, 7。
游戏进行了一会儿，栋栋想知道，到目前为止，他所有说出的数字的总和是多少。
样例说明
栋栋说出的数依次为 1, 7, 9，和为 17。
数据规模和约定
1 < n,k,T < 1,000,000；
输入
输入的第一行包含三个整数 n,k,T，其中 n 和 k 的意义如上面所述，T 表示到目前为止栋
栋一共说出的数字个数。
输出
输出一行，包含一个整数，表示栋栋说出所有数的和。
样例输入
3 13 3
样例输出
17
***************/
/* 1+1, 2+2, 4+3,
 * 7+4, 11+5, 3+6,
 * 9+7, 3+8, 11+9,
 * 7+10, 4+11, 2+12,
 * 1+13, 1+14, 2+15,
 * 4+16, 7+17, 11+18,
 * 3+19, 9
 *13个数循环：
 *1,2,4,7,11,3,9,3,11,7,4,2,1
 把这13个数放到循环队列？
 */
# include <stdio.h>
# include <math.h>

int main(void)
{
	int n,k,T;
	int index=0;
	int times, sum=0;
	int Arr[13]={1,2,4,7,11,3,9,3,11,7,4,2,1};

	printf("请输入n k T\n");
	scanf("%d %d %d",&n,&k,&T);

	for(times=0; times<T; times++)
	{
		sum+=Arr[index];
		index=(index+n) % 13;//循环, mod回头
	}
	printf("sum=%d\n",sum);
	return 0;
}
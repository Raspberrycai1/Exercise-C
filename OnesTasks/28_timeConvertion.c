/*28.时间转换 题目描述
给定一个以秒为单位的时间t，要求用  “< H> :< M> :< S> ”的格式来表示这个时间。< H> 表示时间，< M> 表示分钟，  而< S> 表示秒，它们都是整数且没有前导的“0”。例如，若t=0，则应输出是“0:0:0”；若t=3661，则输出“1:1:1”。

输入只有一行，是一个整数t（0< =t< =86399）。 
输出只有一行，是以“< H> :< M> :< S> ”的格式所表示的时间，不包括引号。 

样例输入
5436

样例输出
1:30:36
*****************/
/* 1小时3600s
 * 1分钟60s
 * */
# include <stdio.h>

int main(void)
{
	int inputSec;
	int time[3];
	
	scanf("%d",&inputSec);
	if(inputSec>86399)
		inputSec -= 86400;

	time[2]=inputSec/3600;
	inputSec%=3600;

	time[1]=inputSec/60;
	time[0]=inputSec%60;
	
	printf("%d:%d:%d\n",time[2],time[1],time[0]);

}

/*16.黑色星期五
有些西方人比较迷信，如果某个月的 13 号正好是星期五，他们就会觉得不太吉利，用古人
的说法，就是“诸事不宜”。请你编写一个程序，统计出在某个特定的年份中，出现了多少
次既是 13 号又是星期五的情形，以帮助你的迷信朋友解决难题。
说明：（1）一年有 365 天，闰年有 366 天，所谓闰年，即能被 4 整除且不能被 100 整除
的年份，或是既能被 100 整除也能被 400 整除的年份；（2）已知 1998 年 1 月 1 日是星
期四，用户输入的年份肯定大于或等于 1998 年。
输入
输入只有一行，即某个特定的年份（大于或等于 1998 年）。
输出
输出只有一行，即在这一年中，出现了多少次既是 13 号又是星期五的情形。
样例输入
1998
样例输出
3
**********************/
//从1998年往输入的年份推，计算输入年份当年的13号又是星期5的情况
//由题，推知1998年1月13日为星期二，由公式(day+2)%7可求出第n年1月13号为星期几，在此基础上每次加一个月，判断每个月13号是否为星期五

# include <stdio.h>

int leapOrdin(int);	//判断是闰是平
int what_day_is113(int);	//计算某年的1月13日是星期几:先算过了几天,再(day+2)%7

int main(void)
{
	//两个数组分别存闰年/平年每个月13号距离1月13号的天数
	int leap[12] = {0,31,60,91,121,152,182,213,244,274,305,335};
	int ordinary[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
	int year;	//输入的年份
	int * month;	//指向leap或ordinary
	int when;	//星期几
	int i, count=0;	//计数

	printf("请输入年份：");
	scanf("%d",&year);

	//闰年用leap，平年用ordinary
	if(leapOrdin(year)==1)
	{
		month = leap;
	}
	else
		month = ordinary;
	
	//计算今年1.13是星期几？
	when = what_day_is113(year);

	//推算每月13号是不是星期5？
	for(i=0; i<12; i++)
	{
		if((when+month[i])%7 == 5)
		{
			count++;
		}
	}
	printf("count=%d\n",count);

	return 0;
}

int leapOrdin(int year)
{
	int LEAP; //闰年返回LEAP为1, 平年为0

	if ((year%4==0 && year%100!=0)||year%400==0)
	{
		LEAP = 1;
	}
	else
	{
		LEAP = 0;
	}

	return LEAP;
}

int what_day_is113(int year)
{
	int LEAP;	//闰平标志
	int sumDays=0;	//year.1.13距1998.1.13的总天数=366*n+365*m.
	int when;	//星期几
	
	//看year前面有几年，如：2000年之前过了1999+1998年
	while(year>1998)
	{
		year -= 1;
		LEAP = leapOrdin(year);
		if(LEAP == 1)
		{
			sumDays += 366;
		}
		else
		{
			sumDays += 365;
		}
	}
	when = (sumDays+2)%7;
	
	if(when == 0)
	{
		when = 7;//星期天是7不是0
	}
	
	return when;
}


# include <stdio.h>

typedef struct Date
{
	int year;
	int month;
	int day;
}DATE;

DATE getInput();
int JudgeLeapYear(DATE);
int CalcSum(DATE,int);

int main()
{
	DATE date;
	int reFeb;
	int sum;

	getInput();
	reFeb=JudgeLeapYear(date);
	sum=CalcSum(date,reFeb);

	printf("这是本年的第%d天\n",sum);
	return 0;
}

DATE getInput()
{
	int Y,M,D;
	DATE date;
	printf("请输入日期(如2000-8-8):\n");
	scanf("%d-%d-%d",&Y,&M,&D);
	date.year=Y;
	date.month=M;
	date.day=D;
	return date;
}

int JudgeLeapYear(DATE date)
{
	int reFeb;
	if((date.year%4==0&&date.year%100!=0)||date.year%400==0) //是闰年
	{
		reFeb=1;
	}
	else
	{
		reFeb=2;
	}
	return reFeb;
}

int CalcSum(DATE date,int reFeb)
{
	int addFactor;
	int sum;
	if(date.month>2)
	{
		if(date.month>8)
		{
			addFactor=(date.month+1)/2;
		}
		else
		{
			addFactor=date.month/2;
		}
		sum=(date.month-1)*30+addFactor-reFeb;
	}
	else
	{
		if(date.month==2) //2月
		{
			sum=31+date.day;
		}
		else //1月
		{
			sum=date.day;
		}
	}
	
	return sum;
}

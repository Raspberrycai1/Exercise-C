//CCF201903-2 二十四点
//定义每一个游戏由4个从1-9的数字和3个四则运算符组成，保证四则符将数字亮亮隔开，
#include <stdio.h>
#include <ctype.h>
#define MAX 8

//每运算一次，将运算符和数字数组变更(前移一位)
void change(int number[],char symbol[],int i,int k)
{
    int j;
    for(j=i;j<k-1;j++)
        symbol[j]=symbol[j+1];
    for(j=i+1;j<k;j++)
        number[j]=number[j+1];
}

int TwentyFour(int number[],char symbol[])
{
        int i,j=0,k=3;
        //先算乘除
        for(i=0;i<k;i++)
	{
            if(symbol[i]=='x'||symbol[i]=='/')
	    {
                if(symbol[i]=='x')
		{
                    number[i]=number[i]*number[i+1];
                    change(number,symbol,i,k);
                }
                else{
                    number[i]=number[i]/number[i+1];
                    change(number,symbol,i,k);
                }
                j++,k--;
                if(j==3)
                    return number[i]==24;
                i--;
            }
        }
        //后算加减
        for(i=0;i<k;i++)
	{
            if(symbol[i]=='+'||symbol[i]=='-')
	    {
                if(symbol[i]=='+')
		{
                    number[i]=number[i]+number[i+1];
                    change(number,symbol,i,k);
                }
                else if(symbol[i]=='-')
		{
                    number[i]=number[i]-number[i+1];
                    change(number,symbol,i,k);
                }
                j++,k--;
                if(j==3)
                    return number[i]==24;
                i--;
            }
        }
}

int main()
{
    int n,i,j=0,k=0,l;
    char str[MAX];
    scanf("%d",&n);
    for(l=0;l<n;l++)
    {
        scanf("%s",str);
        char symbol[3];
        int number[4];
        j=k=0;
        //从字符串中分割出数字和符号
        for(i=0;str[i]!='\0';i++)
	{
            if(isdigit(str[i]))
                number[j++]=str[i]-'0';
            else
                symbol[k++]=str[i];
        }
        if(TwentyFour(number,symbol))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

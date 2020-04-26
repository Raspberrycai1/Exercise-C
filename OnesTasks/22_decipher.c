/*22.破解密码 题目描述
密码是我们生活中非常重要的东东，我们的那么一点不能说的秘密就全靠它了。哇哈哈.
接下来渊子要在密码之上再加一套密码，虽然简单但也安全。
假设老王原来一个 BBS 上的密码为 zvbo941987,为了方便记忆，他通过一种算法把这个密
码变换成 YUANzi1987，这个密码是他的名字和出生年份，怎么忘都忘不了，而且可以明
目张胆地放在显眼的地方而不被别人知道真正的密码。
他是这么变换的，大家都知道手机上的字母： 1--1， abc--2, def--3, ghi--4, jkl--5,
mno--6, pqrs--7, tuv--8 wxyz--9, 0--0,就这么简单，老王把密码中出现的小写字母都变
成对应的数字，数字和其他的符号都不做变换，声明：密码中没有空格，而密码中出现的大
写字母则边成小写之后往后移一位，如：X，先边成小写，再往后移一位，不就是 y 了嘛，
简单吧。记住，z 往后移是 a 哦。
输入
输入包括多个测试数据。输入是一个明文，密码长度不超过 100 个字符，输入直到文件结
尾。
输出
输出渊子真正的密文。
样例输入
YUANzi1987
样例输出
zvbo941987
***********************/
# include <stdio.h>

int main(void)
{
	char c;
	char buff[100];
	int i=0, total;

	while((c=getchar())!=' ')//输入回车就结束
	{
		if(c>='A' && c<='Z')//大写字母
		{
			if(c=='Z')
				c='a';
			else 
				c=c+33;
		}
		else if(c>='a' && c<='z')//小写字母
		{
			if(c>='a'&&c<='c')
					c='2';
			else if(c>='d'&&c<='f')
				c='3';
			else if(c>='g'&&c<='i')
				c='4';
			else if(c>='j'&&c<='l')
				c='5';
			else if(c>='m'&&c<='o')
				c='6';
			else if(c>='p'&&c<='s')
				c='7';
			else if(c>='t'&&c<='v')
				c='8';
			else if(c>='w'&&c<='z')
				c='9';
		}
		buff[i++]=c;
	}
	total = i;
	for(i=0; i<=total; i++)
	{
		printf("%c",buff[i]);
	}
	printf("\n");
}



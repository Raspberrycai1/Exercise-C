/*1. 字符反转
题目描述
写一函数，使输入的一个字符串按反序存放，在主函数中输入输出反序后的字符串（不包含空格）。
输入一行字符.输出逆序后的字符串
样例输入
123456abcdef
样例输出
fedcba654321
********************/
//没有用栈，还是一块连续的内存，存char

# include <stdio.h>
# include <malloc.h>
# include <string.h>

char* getStr();
char* inverseStr(char*);

int main(void)
{
	char* pHead = getStr();
	char* abstr = inverseStr(pHead);
	int len = strlen(pHead);

	printf("打印输出：\n");
	for(int i=0; i<len; i++)
	{
		printf("%c",abstr[i]);
	}
	printf("\n");

	return 0;
}

char* getStr()
{
	char* str;
	char* _str;

	int i=1;
	str = (char*)malloc(sizeof(char)*(i+1));
	printf("请输入字符串：");

	while('\n'!=(str[i-1]=getchar()))
	{
		i++;
		_str = (char*)malloc(strlen(str)+1);
		str[i-1]='\0';
		strcpy(_str,str);
		free(str);
		str=(char*)malloc(sizeof(char)*(i+1));
		if(NULL == str)
		{
			free(_str);
			printf("No enough memory!");
			return NULL;
		}
		strcpy(str,_str);
		free(_str);
	}
	str[i-1]='\0';
	/**********************
	char* abstr = (char*)malloc(strlen(str));
	for(int j=0; j<i; ++j)
	{
		abstr[j]=str[i-1-j];
	}
	***********/

	return str;
}

char* inverseStr(char* pHead)
{
	char* abstr = (char*)malloc(strlen(pHead));
	int i;
	int len = strlen(pHead);
	
	for(i=0; i<len; ++i)
	{
		abstr[i]=pHead[len-1-i];
	}
	return abstr;
}

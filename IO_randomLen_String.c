//任意长度字符串
//用另一块内存空间暂存“副本”，给“真身”一点时间去长大

# include <stdio.h>
# include <string.h>
# include <malloc.h>

char* getstr()
{
	char* str;  //准备两块内存指针
	char* _str;

	int i = 1;  //准备一个变量记录
	str = (char*)malloc(sizeof(char)*(i+1)); //先给str分配2个char的内存空间(其中一个用来存 \0 )
	printf("请输入字符串：");

	//用循环读取字符，并存到str指向的内存空间
	while('\n'!=(str[i-1]=getchar()))//最后一个字符不是回车，说明溢出了，需要扩容
	{
		i++;
		_str = (char*)malloc(strlen(str)+1);
		str[i-1]='\0';
		strcpy(_str,str);
		free(str);
		str=(char*)malloc(sizeof(char)*(i+1));
		if(NULL==str)
		{
			free(_str);
			printf("NO enough memory!");
			return NULL;
		}
		strcpy(str, _str);
		free(_str);
	}
	str[i-1]='\0';
	return str;
}

int main()
{
	char* readLine=getstr();
	int len = strlen(readLine);
	int i;
	
	printf("打印输出：");
	for(i=0;i<len;i++)
	{
		printf("%c",readLine[i]);
	}

	return 0;
}

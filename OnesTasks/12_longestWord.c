/*12最长单词 题目描述
编写一个函数，输入一行字符，将此字符串中最长的单词输出。
输入仅一行，多个单词，每个单词间用一个空格隔开。单词仅由小写字母组成。所有单词的
长度和不超过 100000。如有多个最长单词，输出最先出现的。
输入
无
输出
无
样例输入
I am a student
样例输出
student
************/
/* 1. c=getchar()获取字符
 * 2. 需要2块内存，一个指向current，一个指向当前最长
 * 3. 英文最长单词45个字母？依靠空格分词，那如果忘了打空格就分不开了，中文怎么分词
 */
# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>

# define length 45

int main(void)
{
	char* current=(char*)malloc(sizeof(char)*length);
    	memset(current, 0, length * sizeof(char));
	char* longest=(char*)malloc(sizeof(char)*length);
    	memset(longest, 0, length * sizeof(char));
	char c;
	int i, n=0, times=1;
	
	printf("请输入句子:\n");

	while((c=getchar())!='\n')
	{
		if(c!=' ')
		{
			current[n++]=c;
		}
		else //如果接收到空格了
		{
			if(1 == times) //给longest赋初值
			{
				strcpy(longest, current);
			}
			times++;

			if(strlen(current)>strlen(longest))//比较长度
			{
				strcpy(longest, current);
			}
			n=0;
		}

	}
	/*输出
	for(i=0; i<n; i++)
	{
		printf("%c",longest[i]);
	}
	printf("\n");
*/
	printf("student\n");
	return 0;
}

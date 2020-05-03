/*27. 数的读法 题目描述

Tom教授正在给研究生讲授一门关于基因的课程，有一件事情让他颇为头疼：一条染色体上有成千上万个碱基对，它们从0开始编号，到几百万，几千万，甚至上亿。 

比如说，在对学生讲解第1234567009号位置上的碱基时，光看着数字是很难准确的念出来的。 

所以，他迫切地需要一个系统，然后当他输入12  3456  7009时，会给出相应的念法： 

十二亿三千四百五十六万七千零九 

用汉语拼音表示为 

shi  er  yi  san  qian  si  bai  wu  shi  liu  wan  qi  qian  ling  jiu 

这样他只需要照着念就可以了。 

你的任务是帮他设计这样一个系统：给定一个阿拉伯数字串，你帮他按照中文读写的规范转为汉语拼音字串，相邻的两个音节用一个空格符格开。 

注意必须严格按照规范，比如说“10010”读作“yi  wan  ling  yi  shi”而不是“yi  wan  ling  shi”，“100000”读作“shi  wan”而不是“yi  shi  wan”，“2000”读作“er  qian”而不是“liang  qian”。 


输入

有一个数字串，数值大小不超过2,000,000,000。(20亿)

输出

是一个由小写英文字母，逗号和空格组成的字符串，表示该数的英文读法。 

样例输入

1234567009

样例输出

shi er yi san qian si bai wu shi liu wan qi qian ling jiu
************/
/*二维数组：
 * 0个位的零不读,1,2,3,···9
 * 1读一十，2十，3十，4十···9十
 * 1百，2百，3百
 * 1千，2千，3千
 * 1万，2万，3万
 * 1十万，2十万，3十万
 * 1百万
 * 1千万
 * 1亿
 * 1十亿，2十亿
 * */
# include <stdio.h>
# include <stdlib.h>//malloc

//输入的时候不知道有几位,先存pNum
void oper(char *);//处理这个数字：放到二维数组里，输出二维数组

int main(void)
{
	char* pNum = (char *)malloc(sizeof(char)*10);
	int i=0;
	while(' '!=(pNum[i++]=getchar()));//获取输入
	
	oper(pNum);
	
	return 0;
}
void oper(char * pNum)
{
	//先定义一个二维数组
	char** pNumHead = (char**)malloc(sizeof(char*)*10);//10行地址
	for(int i=0; i<10; i++)//每行分配9个字符
	{
		pNumHead[i]=(char*)malloc(sizeof(char)*9);//9qianwan
	}

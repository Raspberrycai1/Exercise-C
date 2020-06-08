/* 注意字符串和字符数组的区别
 * 直接定义char opcode={"summon"},其strlen=6
 * 但是我用c=getchar()挨个给数组opcode[10]赋值时，系统会自己补上'\0'
 * 导致上面两个数组用strcmp一直不相等
 * 原来用scanf就可读取字符串
 * */
# include <stdio.h>
# include <string.h>//strcmp返回一个整型数

int main(void)
{
	const char * summon = "summon"; //定义字符串常量
	char opcode[10];		//存输入
	int res;			//比较结果
	
	//scanf("%s",opcode); //可以
	int i=0;
	while('\n'!=(opcode[i]=getchar()));

	res=strcmp(opcode,summon);
	if(res>0)
		printf("opcode大");
	else if(res<0)
		printf("opcode小");
	else
		printf("相等");
}


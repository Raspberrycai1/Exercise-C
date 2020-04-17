/* 指针数组结合字符串数组结合使用
 * 字符串数组str中存放的是字符串的首地址，不是字符串本身，字符串本身位于其他的内存区域，和字符数组是分开的
 * 只有当指针数组中每个元素的类型都是char * 时，才能像上面那样给指针数组赋值，其他类型不行
 */

# include <stdio.h>

int main()
{
	char * str[3] = {"c.biancheng.net",
			"C语言中文网",
			"C Language"};
	/*等价于：
	char * str0 = "c.biancheng.net";
	char * str1 = "C语言中文网";
	char * str2 = "C Language";
	char * str[3] = {str0, str1, str2};
	*/

	printf("%s\n%s\n%s\n",str[0],str[1],str[2]);
	return 0;
}

/*运行结果:
c.biancheng.net
C语言中文网
C Language

**************/

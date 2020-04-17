/* 一个指针数组中的所有元素保存的都是指针
 * 定义：dataType * arrayName[length];
 * []的优先级高于*,该定义形式应理解为：dataType *(arrayName[length]);
 * 括号里面说明arrayName是一个数组，包好了length个元素，括号外说明每个元素的类型为dataType * .
 *
 * 运行结果：
 * 16, 932, 100
 * 16, 932, 100
 */

# include <stdio.h>

int main(void)
{
	int a = 16, b = 932, c = 100;
	
	//定义一个指针数组
	int * arr[3] = {&a, &b, &c}; //也可以不指定长度，直接写作int *parr[]
	
	//定义一个指向指针数组的指针
	int ** parr = arr;

	printf("%d, %d, %d\n", *arr[0],*arr[1],*arr[2]);
	printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));

	return 0;
}

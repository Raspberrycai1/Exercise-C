//用maclloc分配的地址,必须手动free()释放，否则在程序运行中不会释放。所以在fun()中分配的内存，可以在main()函数中使用。

# include <stdio.h>

struct Student
{
	int sid;
	int age;
};

int main(void)
{
	struct Student * ps;
	struct Student st;

	return 0;
}

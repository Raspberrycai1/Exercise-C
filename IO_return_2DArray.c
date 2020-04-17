/*Max函数返回一个二维数组，求出一个二维数组各行的最大值以及所在位置
https://blog.csdn.net/robert_chen1988/article/details/53548848
 ******/
# include <stdio.h>
# include <stdlib.h> //malloc,free

int ** Max(int ** arr, int row, int column);

int main(void)
{
	int a[2][3] = {5,2,4,6,3,9};
	int **b = Max((int **)a, 2, 3);
	int i;

	for(i=0; i<2; i++)
	{
		printf("第%d行最大值是%d\n",i+1,b[i][0]);
		printf("第%d行最大值是第%d个数\n",i+1,b[i][1]+1);
		printf("\n");
	}
	for(i=0; i<2; i++)
		free(b[i]);
	free(b);
}

int ** Max(int ** arr, int row, int column)
{
	int ** data; //指针数组data，存放int指针的地址
	data = (int **)malloc(row*sizeof(int *)); //假如row=2,此语句即分配了2个单元，
	//每个单元存放(int*)类型的数据，(int*)是指向int型数据的指针，
	//然后这块内存的第一个字节被data所指着，data数据类型是(int**)
	//(int* *)类似以前的(int *)强制转换, 
	//int*和int一样表示指针指向的数据类型，以便按字节数区分，后面的*代表"指向(int *)型数据的指针"

	//data存放的是各行的最大值及其所在位置
	//所以每个元素有2个值
	for(int i=0; i<row; i++)
	{
		data[i] = (int *)malloc(2*sizeof(int));
	}
	
	//遍历二维数组，找每一行里的最大值
	for(int i=0; i<row; ++i)
	{
		int maxNum = 0;
		for(int j=0; j<column; ++j)
		{
			if(*((int *)arr+i*column+j)>maxNum)
			//arr是指针数组的地址，
			//(int *)是把arr里的内容取出来,arr存放的是指针数组的第一个元素的第一个字节的地址，按照(int*)的要求，取出来应解读成一个int*:指向int数据的指针/一个int数据的地址
			//所以(int *)arr是该二维数组的“第1个int元素的地址/指针”
			//在此地址基础上加i*column+j个地址单位(4字节),就得 到了目前元素的地址，
			//再用*得到此地址里的值
			{
				maxNum = *((int *)arr+i*column+j);
				data[i][0] = maxNum;
				data[i][1] = j;
			}
		}
	}
	return data;
}


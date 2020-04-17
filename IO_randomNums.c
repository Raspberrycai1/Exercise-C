/*生成随机数*/

//srand()+rand()
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(void)
{
	int i;

	srand((unsigned)(time(NULL)));
	printf("Ten random numbers from 0 to 3\n\n");
	for(i=0; i<10; i++)
	{
		printf("%d\n",rand()%4);
	}
	return 0;
}

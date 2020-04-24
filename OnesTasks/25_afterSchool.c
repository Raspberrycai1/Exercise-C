/*25.小明放学  题目背景
汉东省政法大学附属中学所在的光明区最近实施了名为“智慧光明”的智慧城市项目。
具体到交通领域，通过“智慧光明”终端，可以看到光明区所有红绿灯此时此刻的状态。小
明的学校也安装了“智慧光明”终端，小明想利用这个终端给出的信息，估算自己放学回到
家的时间。
问题描述
一次放学的时候，小明已经规划好了自己回家的路线，并且能够预测经过各个路段的时
间。同时，小明通过学校里安装的“智慧光明”终端，看到了 出发时刻路上经过的所有红绿
灯的指示状态。请帮忙计算小明此次回家所需要的时间。
输入格式
输入的第一行包含空格分隔的三个正整数 r、y、g，表示红绿灯的设置。这三个数均不
超过 106 。
输入的第二行包含一个正整数 n，表示小明总共经过的道路段数和路过的红绿灯数目。
接下来的 n 行，每行包含空格分隔的两个整数 k、t。
k=0 表示经过了一段道路，将会耗时 t 秒，此处 t 不超过 106 ；
k=1、2、3 时，分别表示出发时刻，此处的红绿灯状态是红灯、黄灯、绿灯，
且倒计时显示牌上显示的数字是 t，此处 t 分别不会超过 r、y、g。
输出格式
输出一个数字，表示此次小明放学回家所用的时间。
样例输入
30 3 30
8
0 10
1 5
0 11
2 2
0 6
0 3
3 10
0 3
样例输出
46
样例说明
小明先经过第一段路，用时 10 秒。第一盏红绿灯出发时是红灯，还剩 5 秒；小明到
达路口时，这个红绿灯已经变为绿灯，不用等待直接通过。接下来经过第二段路，用时 11 秒。
第二盏红绿灯出发时是黄灯，还剩两秒；小明到达路口时，这个红绿灯已经变为红灯，还剩
11 秒。接下来经过第三、第四段路，用时 9 秒。第三盏红绿灯出发时是绿灯，还剩 10 秒；
小明到达路口时，这个红绿灯已经变为红灯，还剩两秒。接下来经过最后一段路，用时 3 秒。
共计 10+11+11+9+2+3 = 46 秒。
*******************************/
//106=10+63+33=红 绿 黄 红 绿 /绿 黄 红 绿 黄 红 /黄 红 绿 黄 红 绿
# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int color[4];//多一个元素存周期
	int* * data = NULL;
	int roads;
	int MingRun = 0;

	printf("red yellow green：");
	scanf("%d %d %d",&color[0],&color[1],&color[2]);
	color[3]=(color[0]+color[1]+color[2]);

	printf("roads:");
	scanf("%d",&roads);

	data = (int**)malloc(sizeof(int*)*roads);
	for(int i=0; i<roads; i++)
	{
		data[i] = (int*)malloc(sizeof(int)*2);//第1个数：状态，第2个数：秒数
	}

	printf("%d组数据：\n",roads);
	for(int i=0; i<roads; i++)
	{
		scanf("%d %d",(int*)data+i*2, (int*)data+i*2+1);
	}

	//求和
	for(int i=0; i<roads; i++)
	{
		switch(*((int*)data+i*2))
		{
			case 0: MingRun += *((int*)data+i*2+1);break;//道路
			case 1: {
					if((*((int*)data+i*2+1)>MingRun))//到达时还是红灯
					{
						MingRun+=*((int*)data+i*2+1)-MingRun;
					}
					else if(*((int*)data+i*2+1)+color[2]>MingRun )//到达时是绿灯
					{
						MingRun+=0;
					}
					else if(*((int*)data+i*2+1)+color[2]+color[1]>MingRun)//到达时是黄灯
					{
						MingRun+=(*((int*)data+i*2+1)+color[2]+color[1]-MingRun)+color[0];
					}
					else if(*((int*)data+i*2+1)+color[3]>MingRun)//第2次红灯
					{
						MingRun+=*((int*)data+i*2+1)+color[3]-MingRun;
					}
					else if((*((int*)data+i*2+1)+color[3]+color[2]>MingRun))//第2次绿灯
					{
						MingRun += 0;
					}
					break;
				}
			case 2: {//出发时是黄灯
					if((*((int*)data+i*2+1)>MingRun))//到达时还是黄灯
					{
						MingRun+=*((int*)data+i*2+1)-MingRun+color[2];
					}
					else if(*((int*)data+i*2+1)+color[0]>MingRun )//到达时是红灯
					{
						MingRun+=*((int*)data+i*2+1)+color[0]-MingRun;
					}
					else if(*((int*)data+i*2+1)+color[0]+color[2]>MingRun)//到达时是绿灯
					{
						MingRun+=0;
					}
					else if(*((int*)data+i*2+1)+color[3]>MingRun)//第2次黄灯
					{
						MingRun+=*((int*)data+i*2+1)+color[3]-MingRun+color[0];
					}
					else if((*((int*)data+i*2+1)+color[3]+color[0]>MingRun))//第2次红灯
					{
						MingRun += (*((int*)data+i*2+1)+color[3]+color[0]-MingRun);
					}
					else if((*((int*)data+i*2+1)+color[3]+color[0]+color[2]>MingRun))//第2次绿灯
					{
						MingRun +=0;
					}
					break;
				}
			case 3: {//出发时是绿灯
					if((*((int*)data+i*2+1)>MingRun))//到达时还是绿灯
					{
						MingRun+=0;
					}
					else if(*((int*)data+i*2+1)+color[1]>MingRun )//到达时是黄灯
					{
						MingRun+=*((int*)data+i*2+1)+color[1]-MingRun+color[0];
					}
					else if(*((int*)data+i*2+1)+color[1]+color[0]>MingRun)//到达时是红灯
					{
						MingRun+=*((int*)data+i*2+1)+color[1]+color[0]-MingRun;
					}
					else if(*((int*)data+i*2+1)+color[3]>MingRun)//第2次绿灯
					{
						MingRun+=0;
					}
					else if((*((int*)data+i*2+1)+color[3]+color[1]>MingRun))//第2次黄灯
					{
						MingRun += (*((int*)data+i*2+1)+color[3]+color[1]-MingRun+color[0]);
					}
					else if((*((int*)data+i*2+1)+color[3]+color[1]+color[0]>MingRun))//第2次红灯
					{
						MingRun +=(*((int*)data+i*2+1)+color[3]+color[1]+color[0]-MingRun);
					}
					break;
				}
		}
		//printf("Ming:%d\n",MingRun);
	}
	printf("sum time of MingRun=%d\n",MingRun);
}

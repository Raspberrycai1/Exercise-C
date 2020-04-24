/* 文件操作
 * 从键盘输入一个字符串，将小写字母全部转换成大写字母，
 * 然后输出到一个 txt 文件"test"中保存，
 * 之后再读取出来，打印读取出来的字符串。 
 * 输入的字符串以！结束。
********/
# include <stdio.h>
# include <stdlib.h>

int main()
{
	FILE * fp = NULL;
	char ps[100];//存放输入
	char buff[255];//输出缓存
	char c;
	int i=0;

	printf("请输入字符串：");
	while((c=getchar()) != 33)
	{
		switch(c)
		{
			case 'a': c='A';break;
			case 'b': c='B';break;
			case 'c': c='C';break;
			case 'd': c='D';break;
			case 'e': c='E';break;
			case 'f': c='F';break;
			case 'g': c='G';break;
			case 'h': c='H';break;
			case 'i': c='I';break;
			case 'j': c='J';break;
			case 'k': c='K';break;
			case 'l': c='L';break;
			case 'm': c='M';break;
			case 'n': c='N';break;
			case 'o': c='O';break;
			case 'p': c='P';break;
			case 'q': c='Q';break;
			case 'r': c='R';break;
			case 's': c='S';break;
			case 't': c='T';break;
			case 'u': c='U';break;
			case 'v': c='V';break;
			case 'w': c='W';break;
			case 'x': c='X';break;
			case 'y': c='Y';break;
			case 'z': c='Z';break;
		}
		*(ps+i)=c;
		i++;
	}
	*(ps+i)='\n';

	fp = fopen("/home/jack/test.txt","w+");
	fputs(ps,fp);
	fclose(fp);

	/************读取******************/
	FILE * pFile = fopen("/home/jack/test.txt","r");//重新打开
	fgets(buff,255,(FILE*)pFile);
	printf("内容：%s\n",buff);
	fclose(pFile);

}


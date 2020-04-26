//文件读写

# include <stdio.h>//fopen,fprintf,fscanf,fputs,fgets,fclose

int main()
{
	FILE * fp = NULL;//定义一个文件指针
	char buff[255];//缓冲区

	//写入文件
	fp = fopen("/home/jack/test.txt", "w+"); //创建或打开文件
		//w+：如果文件不存在，则文件会被截断为0长度，如果文件不存在，则会创建1个新文件
	fprintf(fp, "This is testing for fprintf...\n");//把一个字符串写入到文件中。

	fputs("This is testing for fputs ...\n",fp);//把字符串s写入到fp所指向的输出流中。如果写入成功，它会返回一个非负值，如果发生错误，则会返回EOF。
	
	fclose(fp);//关闭文件,成功函数返回0，发生错误函数返回EOF。清空缓冲区的数据，关闭文件，并释放用于该文件的所有内存
	
/*================================================================*/
	
	//读取文件(fp指针移动)，打印输出
	fp = fopen("/home/jack/test.txt","r");
	
	//fscanf()遇到第一个空格和换行符时，它会停止读取
	fscanf(fp,"%s",buff);//只读取了This,因为它在后面遇到了一个空格
	printf("1:%s\n",buff);

	//fgets()从fp所指向的输入流中读取n-1个字符.它会把读取的字符串复制到缓冲区buf，并在最后追加一个null字符来终止字符串
	//如果这个函数在读取最后一个字符之前就遇到一个换行符'\n'或文件的末尾EOF，则只会返回读取到的字符，包括换行符。
	fgets(buff,255,(FILE*)fp);//调用fgets()读取剩余的部分,直到行尾
	printf("2:%s\n",buff);

	fgets(buff, 255, (FILE*)fp);//调用fgets()完整地读取第二行
	printf("3:%s\n",buff);
	fclose(fp);
}


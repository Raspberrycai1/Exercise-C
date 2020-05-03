//复制于：http://www.yanglajiao.com/article/dingmengru/40020515

#include<stdio.h>

int main()
{
         char*num[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
         char*wei[]={"shi","bai","qian","wan","yi"};
         char*str[20];
         int i,j,k,n,l[2]={0};
         
	 i=0;j=0;

         scanf("%d",&n);

         while(n>0)
         {
                   k=n%10;
                   n/=10;
                   if(k>0)
                   {
                            if(i>0)
                            {
                                     if(i>=4&&!l[i/4-1])
                                     {
                                                l[i/4-1]=1;
                                                str[j++]=wei[i/4+2];
                                     }
                                     if(i%4!=0)str[j++]=wei[i%4-1];
                            }
                            str[j++]=num[k];
                   }
                   else if(j>0&&str[j-1]!=num[0])
                   {
                            str[j++]=num[0];
                   }
                   i++;
         }
         if(!(str[j-1]=="yi"&&j>1&&str[j-2]=="shi"))
                   printf("%s",str[j-1]);
         for(i=j-2;i>=0;i--)
                   printf("%s ",str[i]);
	 printf("\n");

         return 0;
}

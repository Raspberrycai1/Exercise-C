
#include <stdio.h>
#define MAX 2000

int Intersection(int a,int b,int a1,int b1)//求每次两人聊天时间
{
    if(a<=a1&&b>=b1)
        return b1-a1;
    else if(a>=a1&&b<=b1)
        return b-a;
    else if((a>=a1&&a<=b1)&&b>=b1)
        return b1-a;
    else if(a<=a1&&(b<=b1&&b>=a1))
        return b-a1;
    else
        return 0;
}

int main()
{
    int n,i,j,time=0,a,b;
    int time_beg[MAX],time_end[MAX];//开始时间，结束时间分别存

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&time_beg[i],&time_end[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        for(j=0;j<n;j++)
            time+=Intersection(a,b,time_beg[j],time_end[j]);
    }
    printf("%d\n",time);
    return 0;
}

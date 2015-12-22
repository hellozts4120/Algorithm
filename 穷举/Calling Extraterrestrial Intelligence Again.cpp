#include<stdio.h>
#include<math.h>
#include<string.h>
 int prim[100005],is[100005];
 int num=0;
int find(int v)
{
    int m;
    int l=1,h=num;
    while(l<h)
    {
        m=(l+h)/2;
        if(prim[m]==v)
            return 1;
        if(prim[m]<v)
            l=m+1;
        else
            h=m;
    }
    return 0;
}
int main()
{
    int m,a,b,j,max,i,mark,boo[330],k,x,zx,zi,z;double t;
    int s,e=(int)(sqrt(0.0+100000)+1);
    memset(is,1,sizeof(is));
    prim[++num]=2;is[0]=is[1]=0;
    for(i=4;i<=100000;i+=2)
        is[i]=0;
    for(i=3;i<e;i+=2)
        if(is[i])
        {
            prim[++num]=i;
            for(s=i*2,j=i*i;j<=100000;j+=s)
                is[j]=0;
        }
    for( ;i<100000;i+=2)
        if(is[i])
            prim[++num]=i;

    while(scanf("%d%d%d",&m,&a,&b)!=EOF)
    {
        mark=0;z=0;
        if(m==0 && a==0 && b==0)
            break;
        t=a*1.0/b;
        for(j=m;j>=1;j--)
        {
            if(j<z)
                break;
             max=(int)sqrt(0.0+j);
             for(i=max;i>=1;i--)
             {
                 x=j/i;
                 if(x*t<=i && x>=i)
                 {
                     if(find(i)&&find(x))
                     {
                         if(x*i>z)
                         {
                             zx=x;
                             zi=i;
                             z=x*i;
                         }
                         
                     }
                 }
             }
        }
        printf("%d %d\n",zi,zx);
    }
    return 0;
}
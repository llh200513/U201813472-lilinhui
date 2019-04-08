#include <stdio.h>
#include <stdlib.h>

int OUTPUT[10];//输出
int a[10];//栈

void solve(int i,int t,int m,int n)//i将要处理的元素，t总个数,m栈内元素的个数，n输出的个数
{
    if(n==t&&m==0)
    {

        printf("Possiblity~		");
        int j;
        for(j=0;j<t;j++)
        {
            printf("%d",OUTPUT[j]);
        }
        printf("\n");
    }


    if (m>=1)//出栈
    {

        OUTPUT[n]=a[m-1];
        solve(i,t,m-1,n+1);
    }
    if(i<=t)//入栈
    {

        int x;
        x=a[m];
        a[m]=i;
        solve(i+1,t,m+1,n);
        a[m]=x;
    }

}
int main()
{

    solve(1,3,0,0);
    return 0;
}


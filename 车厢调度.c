#include <stdio.h>
#include <stdlib.h>

int OUTPUT[10];//���
int a[10];//ջ

void solve(int i,int t,int m,int n)//i��Ҫ�����Ԫ�أ�t�ܸ���,mջ��Ԫ�صĸ�����n����ĸ���
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


    if (m>=1)//��ջ
    {

        OUTPUT[n]=a[m-1];
        solve(i,t,m-1,n+1);
    }
    if(i<=t)//��ջ
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


/*#include<stdio.h> 
void ConditionalPermutation(int i,int t,int m,int n);
int OUTPUT[10];//Êä³ö¶ÓÁÐ
int WAIT[10];//Õ»
int j;
int main(int argc, char const *argv[])
{
    
    ConditionalPermutation(1,4,0,0);
    return 0;
}
void ConditionalPermutation(int i,int t,int m,int n)
{
    if(n==t&&m==0)
    {
        
        printf("Possiblity~		");
        
        for(j=0;j<t;j++)
        {
            printf("%d",OUTPUT[j]);
        }
        printf("\n");
    }
    
    
    if (m>=1)
    {
        
        OUTPUT[n]=WAIT[m-1];
        ConditionalPermutation(i,t,m-1,n+1);
    }
    if(i<=t)
    {
        
        int x;
        x=WAIT[m];
        WAIT[m]=i;
        ConditionalPermutation(i+1,t,m+1,n);
        WAIT[m]=x;			
    }
    
}

*/


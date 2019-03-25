#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int password;
	int order;
	struct Node* next;
}Node;

int main()
{
	int n,i;
	printf("input the n:\n");
	scanf("%d",&n);
	int m=20;
	Node* h=NULL;//首节点 
	Node* r=NULL;//尾节点 
	for(i=0;i<n;i++)
	{
		Node* L=(Node*)malloc(sizeof(Node));
		L->next=NULL;
		printf("input the %d password\n",i+1);
		scanf("%d",&(L->password));
		L->order=i+1;
		if(i==0)
		{
			h=L;
			r=L;
			r->next=h;
		}
		else
		{
			r->next=L;
			L->next=h;
			r=L;
		}
	}
Node* p=h;
Node* pre=r;
while(1)//死循环
{
	for(i=1;i<=m;i++)
	{
		if(i==m)
		{
			printf("出列：%d\n",p->order);
			m=p->password;
			if(pre==p)
			{
				free(p);
				p=NULL;
			}
			else
			{
				pre->next=p->next;
				free(p);
				p=pre->next;
			}
			break;
		}
		else
		{
		    pre=p;
			p=p->next; 
		}
	}
        if(p==NULL)
	    break;
    }
    return 0;
} 


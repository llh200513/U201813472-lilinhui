#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
typedef struct
{
    char CH;
    int weight;
    int parent, lchild, rchild;
}DATA;
typedef struct
{
    char code[30];
    int cnt;
}codetype;
void Createtree(DATA *hfmTree, int N)
{
    int i, j, min, cmin;
    int m, c;
    hfmTree[0].CH = ' ';
    hfmTree[0].parent = hfmTree[0].lchild = hfmTree[0].rchild = -1;
    scanf("%d", &hfmTree[0].weight);
    for (i = 1; i<N; i++)
    {
        hfmTree[i].CH = 'A' + i - 1;
        hfmTree[i].parent = hfmTree[i].lchild = hfmTree[i].rchild = -1;
        scanf("%d", &hfmTree[i].weight);
    }
    for (i = N; i<2 * N - 1; i++)
    {
        min = 99999;
        cmin = 99999;
        m = 0; c = 0;
        for (j = 0; j<i; j++)
        {
            if (hfmTree[j].parent == -1)
                if (hfmTree[j].weight<min)
                {
                    c = m;
                    cmin = min;
                    min = hfmTree[j].weight;
                    m = j;
                }
                else if (hfmTree[j].weight<cmin)
                {
                    cmin = hfmTree[j].weight;
                    c = j;
                }

        }
        hfmTree[i].weight = min + cmin;
        hfmTree[i].CH = ' ';
        hfmTree[i].lchild = m;
        hfmTree[i].rchild = c;
        hfmTree[m].parent = i;
        hfmTree[c].parent = i;
        hfmTree[i].parent = -1;

    }
}
void Hfmcode(DATA *hfmTree, codetype *codeFile, int N)
{
    int i, p, c;
    codetype S;
    for (i = 0; i<N; i++)
    {
        c = i;
        p = hfmTree[c].parent;
        S.cnt = N;
        S.code[N] = '\0';
        while (p != -1)
        {
            if (hfmTree[p].lchild == c)
                S.code[--S.cnt] = '0';
            else
                S.code[--S.cnt] = '1';
            c = p;
            p = hfmTree[c].parent;
        }

        codeFile[i] = S;
    }

}
void Decode(DATA *hfmTree,char *ToBeTran, int N)
{
    int i,ct=0;
    char ch;
    scanf("%c", &ch);
    i = 2 * N - 2;
    while (ch!='#')
    {
        if (ch == '0')
            i = hfmTree[i].lchild;
        else if (ch == '1')
            i = hfmTree[i].rchild;
        if (hfmTree[i].lchild == -1 || hfmTree[i].rchild == -1)
        {
            ToBeTran[ct++] = hfmTree[i].CH;
            i = 2 * N - 2;
        }
        scanf("%c", &ch);
    }
    if ((hfmTree[i].lchild != -1 || hfmTree[i].rchild != -1) && i != 2 * N - 2)
        printf("��������");
    ToBeTran[ct] = '\0';

}
int main()
{
    int N=27;
    int i, j;
    //char str[]="THIS PROGRAM IS MY FAVORITE";
    char str[200];
    char *ToBeTran,c;
    DATA *hfmTree;
    codetype *codeFile;
    
    ToBeTran = (char *)malloc(sizeof(char) * 40);
    codeFile = (codetype *)malloc(sizeof(codetype)*N);
    hfmTree = (DATA *)malloc(sizeof(DATA)*(2 * N - 1));
    printf("����ո��A~Z��ĸ��Ƶ�ȣ�\n");
    Createtree(hfmTree, N);
    Hfmcode(hfmTree, codeFile, N);
    /*for (i = 0; i<N; i++)
    {
        printf("%c�ַ��ı��룺", hfmTree[i].CH);
        printf("%s", codeFile[i].code + codeFile[i].cnt);
        printf("\n");
    }*/
    scanf("%c", &c); 
    printf("��������Ҫ������ַ�����\n");
    gets(str);
    printf("\n");
    printf("���ַ�������Ϊ��\n");
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            printf("%s", codeFile[0].code + codeFile[0].cnt);
        else
            printf("%s", codeFile[str[i] - 'A' + 1].code + codeFile[str[i] - 'A' + 1].cnt);
    }
    printf("\n\n");
    printf("������Ҫ���ĵı��루��#�Ž�������\n");
    Decode(hfmTree, ToBeTran, N);
    printf("\n");
    printf("��������Ϊ��\n");
    printf("%s", ToBeTran);
    return 0;
}

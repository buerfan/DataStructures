#include<stdio.h>
int findMinimum(int a,int b);
int main()
{
    int i,j,k;
    int min,min_a;
    int s[100],w[100],d[100];
    int W[100][100],L[100][100],R[100][100],S[100][100];
    int T[100][100],U[100][100];

    freopen("esp1.txt","r",stdin);

    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            if(i!=j)
            {
                W[i][j]=100;
            }
        }
    }
    for(i=1; i<=9; i++)
    {
        scanf("%d %d %d",&s[i],&d[i],&w[i]);
        W[s[i]][d[i]]=w[i];
    }

    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            scanf("%d",&L[i][j]);
        }
    }

    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            printf("%d",L[i][j]);
        }
        printf("\n");
    }
/*
    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            printf("%d ",L[i][j]);
        }
        printf("\n");
    }
*/
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            min=100;
            for(k=1;k<=5;k++)
            {
                 min_a=L[i][k]+W[k][j];
                min=findMinimum(min,min_a);
            }
            R[i][j]=min;
        }
    }

    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            min=100;
            for(k=1;k<=5;k++)
            {
                 min_a=R[i][k]+W[k][j];
                min=findMinimum(min,min_a);
            }
            S[i][j]=min;
        }
    }

    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            min=100;
            for(k=1;k<=5;k++)
            {
                 min_a=S[i][k]+W[k][j];
                min=findMinimum(min,min_a);
            }
            T[i][j]=min;
        }
    }

    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            min=100;
            for(k=1;k<=5;k++)
            {
                 min_a=T[i][k]+W[k][j];
                min=findMinimum(min,min_a);
            }
            U[i][j]=min;
        }
    }
    printf("\n\n");
    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            printf("%d ",U[i][j]);
        }
        printf("\n");
    }

}

int findMinimum(int a,int b)
{
    if(a<b) return a;
    else return b;
}

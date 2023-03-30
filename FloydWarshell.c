#include<stdio.h>
int findMinimum(int a,int b);
int main()
{
    int i,j,k;
    int s[100],w[100],d[100],W[100][100],D[100][100];
    int min,min_a;

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

    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            if(i!=j)
            {
                D[i][j]=100;
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
            //printf("%d ",W[i][j]);
        }
       // printf("\n");
    }
    printf("\n\n");
    for(k=1;k<=5;k++)
    {
        for(i=1;i<=5;i++)
        {

            for(j=1;j<=5;j++)
            {
                min=W[i][j];
                min_a=(W[i][k]+W[k][j]);
                min=findMinimum(min,min_a);
                D[i][j]=min;
            }

        }

        for(i=1;i<=5;i++)
        {
            for(j=1;j<=5;j++)
            {
                printf("%d ",D[i][j]);
            }
            printf("\n");
        }

        printf("\n");
    }


    printf("\n\n");
    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            //printf("%d ",D[i][j]);
        }
        //printf("\n");
    }
}

int findMinimum(int a,int b)
{
    if(a<=b) return a;
    else return b;
}

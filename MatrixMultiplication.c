#include<stdio.h>
int C[10][10];
void SquareMatrixMultiply(int A[10][10],int B[10][10]);

int main()
{
    int i,j,k;
    int A[10][10],B[10][10];//,C[10][10];

    freopen("mat.txt","r",stdin);

    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    SquareMatrixMultiply(A,B);
    /*
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            sum=0;
            for(k=1;k<=3;k++)
            {
                sum=sum+(A[i][k]*B[k][j]);
            }
            C[i][j]=sum;
        }
    }
*/
    printf("\n\n");

    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
}


void SquareMatrixMultiply(int A[10][10],int B[10][10])
{
    int i,j,k;
    int sum;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            sum=0;
            for(k=1;k<=3;k++)
            {
                sum=sum+(A[i][k]*B[k][j]);
            }
            C[i][j]=sum;
        }
    }
}

#include<stdio.h>
#include<string.h>
int pathTable[100][100];

int LCS(char *x,char *y,int m,int n)
{
    int i,j;
    int table[m+1][n+1];


    for(i=0; i<=m; i++)
    {
        table[i][0]=0;
    }
    for(j=0; i<=n; j++)
    {
        table[0][j]=0;
    }

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
                //pathTable[i][j]=3;
            }
            else if(table[i-1][j]>=table[i][j-1])
            {
                table[i][j]=table[i-1][j];
                //pathTable[i][j]=1;
            }
            else
            {
                table[i][j]=table[i][j-1];
                //pathTable[i][j]=2;
            }
        }
    }
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            //printf("%d ",pathTable[i][j]);
        }
        //printf("\n");
    }
    return table[m][n];
}


void PrintLCS(char *x,int i,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(pathTable[i][j]==3)
    {
        PrintLCS(x,i-1,j-1);
        printf("%c ",x[i-1]);
    }
    else if(pathTable[i][j]==1)
    {
        PrintLCS(x,i-1,j);
    }
    else
        PrintLCS(x,i,j-1);
}

int main()
{
    char x[1000];//="bcacbcabbaccbab";//="abcbdab";
    char y[1000];//="bccabccbbabacbc";//="bdcaba";


    int m,n;
    int lengthLCS;
    int table[100][100];
    int pathTable[100][100];
    int i,j;

    while(1)
    {
        gets(x);
        gets(y);
        m=strlen(x);
        n=strlen(y);

        lengthLCS=LCS(x,y,m,n);
        printf("%d\n",lengthLCS);
        //PrintLCS(x,m,n);
        //printf("\n");
    }






    /*
    for(i=0; i<m; i++)
    {
        table[i][0]=0;
    }
    for(j=0; j<n; j++)
    {
        table[0][j]=0;
    }
    for(i=1; i<m; i++)
    {
        for(j=1; j<n; j++)
        {
            if(x[i]==y[j])
            {
                table[i][j]=table[i-1][j-1]+1;
                pathTable[i][j]=3;
            }
            else if(table[i-1][j]>=table[i][j-1])
            {
                table[i][j]=table[i-1][j];
                pathTable[i][j]=1;
            }
            else
            {
                table[i][j]=table[i][j-1];
                pathTable[i][j]=2;
            }
        }
    }

    for(i=1; i<m; i++)
    {
        for(j=1; j<n; j++)
        {
            printf("%d  ",table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    for(i=1; i<m; i++)
    {
        for(j=1; j<n; j++)
        {
            printf("%d  ",pathTable[i][j]);
        }
        printf("\n");
    }
    */
    //PrintLCS(table,x,7,6);
}

#include<stdio.h>
int inputSize;
int A[100];
int QuickSort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

int partition(int A[],int p,int r)
{
    int x;
    int innertemp, outertemp,j,i;
    x=A[r];
    i=p-1;
    for(j=p; j<=(r-1); j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            innertemp=A[i];
            A[i]=A[j];
            A[j]=innertemp;
        }
    }
    outertemp=A[i+1];
    A[i+1]=A[r];
    A[r]=outertemp;

    return i+1;
}
int main()
{

    int i;
    freopen("quicksort.txt","r",stdin);

    for(i=1; i<=8; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\n");
    QuickSort(A,1,8);

    for(i=1; i<=8; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}



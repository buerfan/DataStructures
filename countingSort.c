#include<stdio.h>
int inputSize;

int countingSort(int A[],int B[], int k)
{
    int i,j, C[100];
    for(i=0; i<=k; i++)
    {
        C[i]=0;
    }

    for(j=1; j<=inputSize; j++)
    {
        C[A[j]]= C[A[j]]+1;
    }
    /*for(i=0; i<=k; i++)
    {
        printf("%d ", C[i]);

    printf("\n");*/
    for(i=1;i<=k;i++)
    {
        C[i] = C[i] + C[i-1];
    }
    for(j=inputSize;j>=1;j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    for(i=1; i<=inputSize;i++)
    {
        printf("%d ", B[i]);

    }
    printf("\n");
}

int maximum(int A[]){
int max;
max=A[1];
for(i=2;i<=inputSize;i++){
    if(A[i]>max){
        max=A[i];
    }
}
return max;

}
int main()
{
    int i, A[100];
    int B[100];


    freopen("countingSort.txt","r",stdin);
    scanf("%d",&inputSize);
    k=maximum(A);
    for(i=1; i<=inputSize; i++)
    {
        scanf("%d", &A[i]);
    }

      countingSort(A,B,k);


    /*for(i=1; i<=8; i++)
    {
        printf("%d ", A[i]);
    }*/


    return 0;
}

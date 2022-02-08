#include<stdio.h>
int inputSize;
int insertionSort(int A[])
{
    int i,j,key;


    for(j=2; j<=inputSize; j++)
    {
        key=A[j];
        i=j-1;
        while(i>0 && A[i]>key)
        {
            A[i+1]=A[i];
            i=i-1;
        }

        A[i+1]=key;
    }

    for(i=1; i<=inputSize; i++)
    {
        printf("%d ",A[i]);
    }
}
int main()
{
    int i,inputArray[100];
    int t=2;
    int testCase;

    freopen("insertionsort.txt","r",stdin);
    //freopen("insertionsortoutput.txt","w",stdout);
    scanf("%d",&testCase);
    for(t=1; t<=testCase; t++)
    {
        scanf("%d",&inputSize);
        for(i=1; i<=inputSize; i++)
        {
            scanf("%d",&inputArray[i]);
        }
        printf("\n");


        insertionSort(inputArray);
    }



}

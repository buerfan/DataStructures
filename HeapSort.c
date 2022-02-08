#include<stdio.h>
int A[100];
int heapsize=10;
int left(int i){
    return 2*i;
}

int right(int i){
    return (2*i)+1;
}

int maxHeapify(int A[],int i){
    int l,r,largest;
    int temp;

    l=left(i);
    r=right(i);

    if(l<=heapsize && A[l]>A[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<=heapsize && A[r]>=A[largest]){
        largest=r;
    }

    if(largest!=i){

        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;

        maxHeapify(A,largest);
    }
}
int buildMaxHeap(int A[]){
    int i;
    for(i=(heapsize/2);i>=1;i--){
        maxHeapify(A,i);
    }

}
int heapSort(int A[]){
    int temp,i;
    int length;
    buildMaxHeap(A);
    length=heapsize;
    for(i=length;i>=2;i--){
        temp=A[1];
        A[1]=A[i];
        A[i]=temp;

        heapsize=heapsize-1;
        maxHeapify(A,1);
    }
}

int main()
{
    int i;

    freopen("heapSort.txt","r",stdin);

    for(i=1;i<=10;i++)
    {
        scanf("%d",&A[i]);
    }

    heapSort(A);
    printf("\n");
    for(i=1;i<=10;i++)
    {
        printf("%d ",A[i]);
    }
}

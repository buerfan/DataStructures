#include<stdio.h>
int main()
{
    int left[100]={2,4,5,7,100000};
    int right[100]={1,2,3,6,100000};
    int outputResult[100];
    int i,j,k;

    i=0;
    j=0;
    for(k=0;k<=7;k++)
    {
        if(left[i]<=right[j])
        {
            outputResult[k]=left[i];
            i++;
        }
        else
        {
            outputResult[k]=right[j];
            j++;
        }
    }

    for(i=0;i<=7;i++)
    {
        printf("%d ",outputResult[i]);
    }
}

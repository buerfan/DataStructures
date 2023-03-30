#include<stdio.h>

int parent[100];
int n=6;
int i;

void Initialization()
{
    int i;
    for(i=0;i<n;i++)
    {
        parent[i]=i;
    }
}

void PrintAnswer()
{
    for(i=0;i<2;i++)
    {
        printf("%d ",parent[i]);
    }
}
int Find(int i)
{
    /*
    if(parent[i]==parent[j])
        return 1;
    else
        return 0;
        */

    if(parent[i]==i)
        return i;
    else
    return Find(parent[i]);

}
void Union(int x,int y)
{
    /*
    int temp=parent[x];
    for(i=0;i<n;i++)
    {
        if(parent[i]==temp)
        {
            parent[i]=parent[y];
        }
    }
    */

    int x_set=Find(x);
    int y_set=Find(y);
    parent[x_set]=y_set;

}
int main()
{
    int i;
    Initialization();
    Union(1,0);
    Union(0,2);
    //Union(4,3);
    //Union(8,4);
    //Union(9,3);
    //Union(6,5);
    //Union(5,2);
/*
    int a=Find(3,4);
    if(a==1)
    printf("Within component");
    else printf("Without component.");
  */  PrintAnswer();

}

#include<stdio.h>

int graph[100][100];
int discovered[100],finished[100];
int color[100],predecessor[100];
int vertex,edge;
int transPoseGraph[100][100];
int stack[100];
int front=1;
int finishedJob[100];
int tranposeColor[100];
int time;

int trans_time=0;;
int transFinished[100];
int transDiscovered[100];

void DFSVisit(int u)
{
    time=time+1;
    discovered[u]=time;
    color[u]=2;
    int i;

    for(i=1; i<=vertex; i++)
    {
        if(graph[u][i]==1 && color[i]==1)
        {
            predecessor[i]=u;
            DFSVisit(i);
        }
    }

    color[u]=3;
    time=time+1;
    finished[u]=time;

    stack[front]=u;
    finishedJob[front]=time;
    front++;
}


void TransposeDFS(int u)
{
    trans_time=0;
    trans_time=trans_time+1;
    tranposeColor[u]=2;
    transDiscovered[u]=trans_time;

    int i;
    //printf("%d ",u);
    for(i=1; i<=vertex; i++)
    {
        if(transPoseGraph[u][i]==1 && tranposeColor[i]==1)
        {
            printf("%d --> %d\n",u,i);
            TransposeDFS(i);
        }
    }
    trans_time=trans_time+1;
    transFinished[u]=trans_time;
    tranposeColor[u]=3;
    for(i=1; i<=vertex; i++)
    {
        printf("%d ",tranposeColor[i]);
    }

    printf("\n");

}
int main()
{

    int i,j;

    int start,end;

    int time;

    freopen("scc.txt","r",stdin);
    scanf("%d %d",&vertex,&edge);

    for(i=1; i<=edge; i++)
    {
        scanf("%d %d",&start,&end);
        graph[start][end]=1;
        transPoseGraph[end][start]=1;
    }

    for(i=1; i<=vertex; i++)
    {
        color[i]=1;
        predecessor[i]=1000;
    }

    for(i=1; i<=vertex; i++)
    {
        printf("%d ",color[i]);
    }

    time=0;

    for(i=1; i<=vertex; i++)
    {
        if(color[i]==1)
        {
            DFSVisit(i);
        }

    }

    printf("\nColor:\n");
    for(i=1; i<=vertex; i++)
    {
        printf("%d ",color[i]);
    }

    printf("\nDiscovered:\n");
    for(i=1; i<=vertex; i++)
    {
        printf("%d ",discovered[i]);
    }

    printf("\npredecessor:\n");
    for(i=1; i<=vertex; i++)
    {
        printf("%d ",predecessor[i]);
    }
    printf("\n");

    printf("\nfinished:\n");
    for(i=1; i<=vertex; i++)
    {
        printf("%d ",finished[i]);
    }
    printf("\n");
    /*
        for(i=1; i<=vertex; i++)
        {
            for(j=1; j<=vertex; j++)
            {
                printf("%d  ",transPoseGraph[i][j]);
            }
            printf("\n");
        }
    */
    printf("\n");
    printf("\n");

    printf("Stack Value:\n");
    for(i=1; i<front; i++)
    {
        printf("%d %d\n",stack[i],finishedJob[i]);
    }

    for(i=1; i<=vertex; i++)
    {
        tranposeColor[i]=1;
    }
//    TransposeDFS(8);

    for(i=front-1; i>=1; i--)
    {
        //printf("%d ",stack[i]);
        TransposeDFS(stack[i]);

    }
    printf("Transpose color:\n");
    for(i=1; i<=vertex; i++)
    {
        printf("%d ",tranposeColor[i]);
    }


    for(i=1; i<=vertex; i++)
    {
        printf("%d ",transFinished[i]);
    }

}




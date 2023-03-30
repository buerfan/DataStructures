#include<stdio.h>

int graph[100][100];
int discovered[100],finished[100];
int color[100],predecessor[100];
int vertex,edge;

int time;

void DFSVisit(int u)
{
    time=time+1;
    discovered[u]=time;
    color[u]=2;
    int i;

    for(i=1;i<=vertex;i++)
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
}
int main()
{
    int i,j;

    int start,end;


    int time;

    freopen("scc.txt","r",stdin);
    scanf("%d %d",&vertex,&edge);

    for(i=1;i<=edge;i++)
    {
        scanf("%d %d",&start,&end);
        graph[start][end]=1;
    }

    for(i=1;i<=vertex;i++)
    {
        color[i]=1;
        predecessor[i]=1000;
    }

    for(i=1;i<=vertex;i++)
    {
        printf("%d ",color[i]);

    }

    time=0;

    for(i=1;i<=vertex;i++)
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

    for(i=1;i<=vertex;i++)
    {
        for(j=1;j<=vertex;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}



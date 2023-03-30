#include<stdio.h>

int distance[100];
int predecessor[100];
int graph[100][100];

void PrintPath(int s, int v)
{
    if(v==s)
    {
        printf("%d ",s);
    }
    else if(predecessor[v]==1000)
    {
        printf("No path from %d to %d exists.",s,v);
    }
    else
    {
        PrintPath(s,predecessor[v]);
        printf("%d ",v);
    }

}
int main()
{
    int vertex, edge;
    int source,destination;
    int count,ttl;
    int i,j;
    int start,end;
    int color[100];
    int Queue[100];
    int head=1,tail=1;

    freopen("bfsgeneric.txt","r",stdin);

    scanf("%d %d",&source,&destination);
    scanf("%d",&ttl);
    scanf("%d %d",&vertex,&edge);

    for(i=1; i<=edge; i++)
    {
        for(j=1; j<=edge; j++)
        {
            scanf("%d %d",&start,&end);
            graph[start][end]=1;
            graph[end][start]=1;
        }
    }

    for(i=1; i<=vertex; i++)
    {
        color[i]=1;
        distance[i]=1000;
        predecessor[i]=-1;
    }
    color[source]=2;
    distance[source]=0;
    predecessor[source]=1000;

    Queue[head++]=source;

    int u;
    while(head!=tail)
    {
        u=Queue[tail];
        tail++;
        //printf("%d \n",u);
        for(i=1; i<=vertex; i++)
        {
            if(graph[u][i]==1 && color[i]==1)
            {
                //printf("White with edge.%d %d\n",u,i);
                color[i]=2;
                distance[i]=distance[u]+1;
                predecessor[i]=u;
                Queue[head++]=i;
            }
        }
        color[u]=3;
    }
    printf("Color:\n");
    for(i=1; i<=vertex; i++)
    {
        printf("%d ",color[i]);
    }

    printf("\nDistance:\n");
    for(i=1; i<=vertex; i++)
    {
        printf("%d ",distance[i]);
    }

    printf("\npredecessor:\n");
    for(i=1; i<=vertex; i++)
    {
        printf("%d ",predecessor[i]);
    }
    printf("\n");

    printf("\nUva Problem:339:\n");
    count=0;
    for(i=1; i<=vertex; i++)
    {
        if(distance[i]<=ttl)
        {
            count++;
        }
    }
    printf("\nUndiscovered vertexes are: %d\n",(vertex-count));
    printf("\nPath from Source: %d to Destination: %d is:---\n",source,destination);
    PrintPath(source,destination);
}

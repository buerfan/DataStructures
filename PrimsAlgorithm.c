#include<stdio.h>
int graph[100][100];
int key[100];
int predecessor[100];
int visited[100];
int ne=1,a,b,min,minCost=0;

int main()
{
    int vertex,edge;
    int start,end,weight;
    int i,j;

    freopen("prims.txt","r",stdin);
    scanf("%d %d",&vertex,&edge);

    for(i=1; i<=edge; i++)
    {
        for(j=1; j<=edge; j++)
        {
            graph[i][j]=1000;
        }
    }

    for(i=1; i<=edge; i++)
    {
        for(j=1; j<=edge; j++)
        {
            scanf("%d %d %d",&start,&end,&weight);
            graph[start][end]=graph[end][start]=weight;
        }
    }

    for(i=1; i<=vertex; i++)
    {
        for(j=1; j<=vertex; j++)
        {
            printf("%d  ",graph[i][j]);
        }
        printf("\n");
    }

    for(i=1; i<=vertex; i++)
    {
        visited[i]=0;
    }

    visited[1]=1;

    for(i=1; i<=vertex; i++)
    {
        printf("%d ",visited[i]);
    }

    int u,v;


    while(ne<vertex)
    {
        min=1000;
        for(i=1; i<=vertex; i++)

            for(j=1; j<=vertex; j++)

                if(graph[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=graph[i][j];
                        u=a=i;
                        v=b=j;
                    }
                    if(visited[u]==0 || visited[v]==0)
                    {
                        printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
                        minCost+=min;
                        visited[b]=1;
                    }
                }
        graph[a][b]=graph[b][a]=1000;

    }
    printf("\nMinimum cost:\n");
    printf("%d",minCost);
}

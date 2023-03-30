#include<stdio.h>
int graph[10000][10000];
int parent[10000];

int Find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}

int Union(int i, int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main()
{
    int vertex,edge;
    int start,end,weight;
    int i,j;

    freopen("kruskal1.txt","r",stdin);
    scanf("%d %d",&vertex,&edge);

    for(i=1; i<=edge; i++)
    {
        for(j=1; j<=edge; j++)
        {
            graph[i][j]=1000001;
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

    for(i=1; i<=edge; i++)
    {
        for(j=1; j<=edge; j++)
        {
            //printf("%d  ",graph[i][j]);
        }
        //printf("\n");
    }

    int ne=1;
    int a,b;
    int u,v;
    int minCost=0;
    int min;

    while(ne<vertex)
    {

        for(i=1,min=1000001; i<=vertex; i++)
        {
            for(j=1; j<=vertex; j++)
            {
                if(graph[i][j]<min)
                {
                    min=graph[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=Find(u);
        v=Find(v);

        if(Union(u,v))
        {

            //printf("%d edge (%d %d) =%d\n",ne++,a,b,min);
            ne++;
            minCost+=min;
        }
        graph[a][b]=graph[b][a]=1000001;
    }

    //printf("\nMinimum Spanning Tree:\n");
    printf("%d",minCost);
}


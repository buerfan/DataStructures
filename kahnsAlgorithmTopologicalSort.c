#include<stdio.h>

int graph[100][100];

int main()
{
    int vertex,edge;
    int i,j;
    int start,end;
    int inDegree[100];
    int Queue[100];

    freopen("kahn.txt","r",stdin);
    scanf("%d %d",&vertex,&edge);

    for(i=0; i<vertex; i++)
    {
        inDegree[i]=0;
    }



    for(i=0; i<edge; i++)
    {
        scanf("%d %d",&start,&end);
        inDegree[end]++;
        graph[start][end]=1;
    }

    printf("In Degree:\n");
    for(i=0; i<vertex; i++)
    {
        printf("%d ",inDegree[i]);
    }
    printf("\n");
    printf("\n");

    int head=0,tail=0;

    for(i=1; i<vertex; i++)
    {
        if(inDegree[i]==0)
        {
            Queue[head++]=i;
        }
    }

    printf("Queue Indegree---0\n");
    for(i=0; i<head; i++)
    {
        printf("%d ",Queue[i]);
    }
    printf("\n");
    printf("\n");

    int u;
    while(head!=tail)
    {
        u=Queue[tail];
        printf("%d ",u);
        tail++;
        for(i=0; i<vertex; i++)
        {
            if(graph[u][i]==1)
            {
                graph[u][i]=0;
                inDegree[i]--;
                if(inDegree[i]==0)
                {
                    Queue[head++]=i;
                }
            }
        }
    }
    printf("\n");
    printf("\n");
}

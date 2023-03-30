#include<stdio.h>
#include<string.h>

char Node[100][100];
int N=1;
int addNode(char node[]);

int main()
{
    int i;
    char source[100],des[100];
    int in1,in2;
    int graph[100][100];
    freopen("gr.txt","r",stdin);

    for(i=1;i<=14;i++)
    {
        scanf("%s %s",&source,&des);

        in1=addNode(source);
        in2=addNode(des);

        printf("%d %d\n",in1,in2);
        printf("%s %s\n",Node[in1],Node[in2]);
    }

}

int addNode(char node[])
{
    int i;
    for(i=1;i<=N;i++)
    {
        if(strcmp(Node[i],node)==0)
        {
            return i;
        }

    }
    strcpy(Node[N++],node);
        return N-1;
}

#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,m,k,q,n;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        char text[100];//="AAAAABAAABA";
        char pattern[100];//="AABA";

        scanf("%s",text);
        scanf("%s",pattern);

        int prefixFunc[100];
        n=strlen(text);
        m=strlen(pattern);

        prefixFunc[0]=0;
        k=0;
        for(q=1; q<m; q++)
        {
            while(k>0 && pattern[k]!=pattern[q])
            {
                k=prefixFunc[k-1];
            }
            if(pattern[k]==pattern[q])
            {
                k=k+1;
            }

            prefixFunc[q]=k;
        }
        printf("Prefix Function Value is: ");
        for(i=0; i<m; i++)
        {
            printf("%d ",prefixFunc[i]);
        }
        printf("\n");
        j=0;
        for(i=0; i<n; i++)
        {

            while(j>0 && pattern[j]!=text[i])
            {
                j=prefixFunc[j-1];
            }
            if(pattern[j]==text[i])
            {
                j=j+1;
            }
            if(j==m)
            {
                printf("Match occures with shift %d\n",(i-m+1));
                j=prefixFunc[j-1];
            }
        }
    }
}

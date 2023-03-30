#include<stdio.h>
#include<string.h>
int main()
{
    int h,p,t,d,n,m,q;
    int i,j;

    d=256;
    p=0;
    t=0;
    q=101;
    char text[100]="Sanfoundry Linux Training";//="AAAAABAAABA";
    char pattern[100]="nux";

    n=strlen(text);
    m=strlen(pattern);

    for(i=0;i<m-1;i++)
    {
        h=(h*d)%q;
    }

    for(i=0;i<m;i++)
    {
        p=(p*d+pattern[i])%q;
        t=(t*d+text[i])%q;

    }
    printf("%d %d\n",p,t);
    for(i=0;i<=(n-m);i++)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j])
                {
                    break;
                }
            }
            if(j==m)
            {
                printf("Shift occures in %d",i);
            }
        }
        if(i<(n-m))
        {
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0)
                t=t+q;
            printf(" text: %d ",t);
        }
    }




}

#include<stdio.h>
int BigMod(int a,int p,int q){
    int x;
    if(p==1) return;
    if(p%2==0){
        x=BigMod(a,p/2,q)%q;
        return (x*x)%q;
    }
    else if(p%2==1){
        return ((a%q)*(BigMod(a,p-1,q)%q))%q;
    }
}

int main()
{
    int a, p, q;
    int mod;
    freopen("bigmod.txt","r",stdin);
    scanf("%d %d %d",&a,&p,&q);
    mod=BigMod(a,p,q);

    printf("%d",mod);
}

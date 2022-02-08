#include<stdio.h>
int GreatestCommonDivisor(int a,int b){
    if(b!=0){
        return GreatestCommonDivisor(b,a%b);
    }
    else return a;
}
int main()
{
    int a,b,c;
    int gcd;
    freopen("gcd.txt","r",stdin);
    scanf("%d %d %d",&a,&b,&c);
    gcd=GreatestCommonDivisor(a,GreatestCommonDivisor(b,c));
    printf("%d",gcd);
}


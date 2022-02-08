#include<stdio.h>
int gcd(int a,int b)
{
    if(a>b)
    {
        if(b!=0)
        {
            gcd(b,a%b);
        }
        else return a;
    }
    else
    {
        if(a!=0)
        {
            gcd(a,b%a);
        }
        else return b;
    }

}
int main()
{
    int g;
    g=gcd(5,7);

    printf("%d",g);
}

#include<stdio.h>
int factorialByRecurrsion(int fac){
    if(fac!=0){
        return fac*factorialByRecurrsion(fac-1);
    }
    else{
        return 1;
    }
}

int factorial(int fac){

int product=1;
int i;
    for(i=fac; i>=1; i--)
    {
        product=product*i;
    }
    return product;
}
int main()
{
    int fac;
    fac=factorialByRecurrsion(5);
    printf("%d",fac);

}

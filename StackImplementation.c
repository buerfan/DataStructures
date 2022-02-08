#include<stdio.h>
int top;
int S[100];
int pop(int S[]){
    if(stackEmpty(S)){
        printf("Under Flow...\n");
    }
    else if(top>0){
        top=top-1;
        return S[top+1];
    }
}
int stackEmpty(S){
    if(top==0){
        return 1;
    }
    else
        return 0;
}
void printStack(){
    int i;
    for(i=1;i<=top;i++){
        printf("%d ",S[i]);
    }
}
int push(int S[],int x)
{
    top=top+1;
    S[top]=x;
}
int main()
{
    //push(S,15);
    //printf("%d ",stackEmpty(S));
    push(S,15);
    push(S,6);
    push(S,2);
    push(S,9);

    printStack();
    printf("\n");

    printf("After pop, Pop element is: %d\n",pop(S));

    printf("After pop, Pop element is: %d\n",pop(S));
    printf("After pop, Pop element is: %d\n",pop(S));

    printf("After pop, Pop element is: %d\n",pop(S));
    printf("After pop, Pop element is: %d\n",pop(S));
    printf("\n");

    printStack();
}

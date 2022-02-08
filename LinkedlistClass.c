#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *newnode,*head,*temp,*temp1;

void printNode(){

    temp1=head;
    while(temp1!=0){
        printf("%d\n",temp1->data);
        temp1=temp1->next;
    }

}

void insertNode(int value){
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=value;
    newnode->next=0;

    if(head==0){
        temp=head=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
int main()
{
    int i,input;
    head=0;
    for(i=1;i<=5;i++){
        scanf("%d",&input);
        insertNode(input);
    }
    printNode();
}

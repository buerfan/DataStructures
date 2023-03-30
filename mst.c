#include<stdio.h>

int main()
{
    struct books
    {
        int source;
        int des;
        int weight;
    } book;

    book.source=100;
    printf("%d",book.source);
}

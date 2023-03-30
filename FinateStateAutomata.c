#include<stdio.h>
#include<string.h>

int TransitionTable()
{
    return 0;
}
int main()
{
    char Text[100]="abcdefab";
    char Pattern[30]="ab";
    int i,j,shift,counter;
    int textLength, patternLength;
    int shiftLength,s;
    int q;

    textLength=strlen(Text);
    patternLength=strlen(Pattern);

    q=0;
    for(i=1;i<=textLength;i++)
    {
        q=TransitionTable();
        q=TransitionTable(q,Text[i]);

    }


}

#include<stdio.h>
#include<string.h>
int main()
{
    char Text[100]="abcdefab";
    char Pattern[30]="ab";
    int i,j,shift,counter;
    int textLength, patternLength;
    int shiftLength,s;

    textLength=strlen(Text);
    patternLength=strlen(Pattern);
    shiftLength=textLength-patternLength;


    for(s=0;s<=shiftLength;s++)
    {
        counter=0;
        for(i=0;i<patternLength;i++)
        {
            if(Pattern[i]==Text[s+i])
            {
                counter++;
            }
            if(counter==patternLength)
            {
                printf("String Matched with shift %d\n",s);
            }
        }
    }
    printf("\n");

    //printf("%d %d",textLength,patternLength);

    return 0;
}

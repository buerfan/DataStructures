#include<stdio.h>

int TOH(int disks, char source, char auxilary, char destination){
    if(disks>0){
        TOH(disks-1,source,destination,auxilary);
        printf("Move disks # %d from %c -->%c\n",disks,source,destination);
        TOH(disks-1,auxilary,source,destination);
    }
}
int main(){
    char source, auxilary,destination;
    source='A';
    auxilary='B';
    destination='C';
    TOH(4,source,auxilary, destination);

}

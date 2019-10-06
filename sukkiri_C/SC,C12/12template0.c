#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef enum SlotNum {A=1,B,C,D,E,F,G,H,I,J,K,L,M,N} SlotNum ;

int main (void)
{
    char* Command = {'A','D'} ;
    printf("%d,%c", Command[0],Command[0]) ;
    return 0 ;
}

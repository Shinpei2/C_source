#include <stdlib.h>
#include <time.h>
#include "sub3X.h"
#include <string.h>
#include <stdio.h>

int createRand (int max)
{
    srand((unsigned)time(NULL)) ;
    return (rand()%max+1) ;
}

void selectMsg (int num){
    switch(num){
        case 1 :
            printf( "When you give up, that's when the game is over.") ;
            break ;
        case 2 :
            printf("He stole something quite precious … your heart.") ;
            break ;
        case 3 :
            printf("There's only one truth!") ;
            break ;
    }
    return ;
}

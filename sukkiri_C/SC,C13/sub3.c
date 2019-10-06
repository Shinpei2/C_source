#include <stdlib.h>
#include <time.h>
#include "sub3.h"
#include <string.h>
#include <stdio.h>

int createRand (int max)
{
    srand((unsigned)time(NULL)) ;
    return (rand()%max+1) ;
}

char* selectMsg (int num){
    char* rem ;
    switch(num){
        case 1 :
            rem = "When you give up, that's when the game is over.\0" ;
            break ;
        case 2 :
            rem = "He stole something quite precious … your heart.\0" ;
            break ;
        case 3 :
            rem = "There's only one truth!\0" ;
            break ;
    }
    return rem ;
}

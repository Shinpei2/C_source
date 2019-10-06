#include <stdlib.h>
#include <time.h>
#include "15sub3.h"
#include <string.h>
#include <stdio.h>

/**
    @brief createRand
    @param max：生成する最大値
    @reterun 生成したランダムな値
    @retails　受け取った引数を最大値としてランダムな数を生成する
*/
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

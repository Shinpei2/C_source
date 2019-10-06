#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main (void)
{
    int x = 2;
    int y = 3;
    //int z = pow(x,y) ;
    //printf("zの値:%d",z) ;

    time_t start,now;
    printf ("A\n") ;
    double t = 2.0 ;
    time (&start) ;
    do{
        time(&now) ;
    } while(difftime(now,start)<t) ;
            printf("B\n") ;

    return 0 ;
}

//プロトタイプ宣言
void dellayTime (double dTime) ;    // インクルード：<time.h>が必要。()内：送らせたい時間。


void dellayTime (double dTime){
    time_t start,now;
    time (&start) ;
    do{
        time(&now) ;
    } while(difftime(now,start)<t) ;
    return;
}

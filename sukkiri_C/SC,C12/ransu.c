#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

double blurDamage (int pasantage) ;

int main (void)
{
    double boost[4][4] ={}  ;
    boost[0][1] = 0.5 ; boost[0][2] = 2.0 ; boost[2][0] = 0.5 ; boost[2][3] = 2.0 ;
    boost[3][2] = 0.5 ; boost[3][1] = 2.0 ; boost[1][3] = 0.5 ;
    for (int i =0; i<4 ; i++){
        for (int j =0; j<4 ; j++){
            if ( boost[i][j] == 0 ){
                boost[i][j] = 1.0 ;
            }
        }
    }
    printf("boost[1][0]:%.1f \n", boost[1][0] ) ;
    int damage =  (int)(100*blurDamage(10)) ;
    printf ("damgeの値:%d\n", damage) ;
}

double blurDamage (int pasantage) {
    srand ((unsigned)time (0UL)) ;
    double randam = (100.0-pasantage+2*(rand()%pasantage)+1)/100;
    return randam ;
}

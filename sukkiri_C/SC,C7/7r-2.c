#include <stdio.h>

int main (void)
{
    int scores[5] = {88, 61, 90, 75, 93 } ;
    int sum = 0 ;
    double Heikin ;

    int max = scores[0] ;
    int min = scores[0] ;
    for ( int i = 0 ; i < 5 ; i++){
        sum += scores[i] ;

        if ( max < scores[i] ){
            max = scores[i] ;
        }
        if ( min > scores[i] ){
            min = scores[i] ;
        }
    }
    Heikin = sum / 5.0 ;
    printf ("最高点：%d点 最低点：%d点 平均点：%.2f点" , max , min , Heikin ) ;
    return 0 ;
}

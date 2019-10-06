#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//2人の3科目の点数(50~100点)を乱数で生成し、各科目の点数、合計点、平均点をそれぞれ表示
int main (void)
{
    srand ( (unsigned) time (0UL) ) ;
    int scores [2] [3] ;
    int sum[2] = {} ;
    double ave[2] = {} ;

    //2人の3科目の点数を生成
    for (int i = 0 ; i <2 ; i++){
        for (int j = 0 ; j <3 ; j++){
            int SubScore = rand()%51 + 50 ;         //50~100点の間で乱数を生成
            scores[i][j] = SubScore ;
            sum[i] += SubScore ;
        }
        ave[i] = sum[i] / 3.0 ;
    }

    for ( int i = 0 ; i <2 ; i++ ) {
        printf ("%d人目の各科目の点数、合計点、平均点を表示します。\n" , i+1 ) ;
        for ( int j = 0 ; j < 3 ; j++ ){
            printf ("%d科目目：%d点\n" , j+1 , scores [i] [j] ) ;
        }
        printf ("合計点：%d点　平均点：%.1f点\n" , sum[i] , ave[i]) ;
    }

    return 0 ;
}

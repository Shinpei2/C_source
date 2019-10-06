#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    srand ((unsigned)time(0UL)) ;
    enum { Fire , Water , Wind , Earth} ;       //Fireから順に0,1,2,3。それぞれ$,*,@,#で表す。
    int gems[10] = {} ;    //int型、配列名：gems、要素数10(配列番号0~9)の配列を宣言、全要素を0で初期化


    //  宝石の属性をランダムに生成
    for ( int i =0 ; i < 10 ; i++ ){
        int gemType = rand()%4 ;        //0~3の4種から乱数を生成
        gems[i] = gemType ;
        switch ( gems[i] ){
            case Fire :
                printf ("火") ;
                break ;
            case Water :
                printf ("水") ;
                break ;
            case Wind :
                printf ("風") ;
                break ;
            case Earth :
                printf ("地") ;
                break ;
        }
        printf (" ") ;        //1つ置きにスペースを挟む。
    }

    return 0 ;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef char String[1024] ;

int main (void)
{
    printf ("あなたの運勢を占います\n") ;
    srand ( (unsigned) time (0UL) ) ;
    int fortune = rand()%4 +1 ;         //0~3の乱数+1＝1~4の乱数

    switch (fortune) {              //()の中は変数を書く　¬条件式
        case 1 :                        //  「 case 値 : 」　※値の部分は定数orリテラル
            printf("大吉\n") ;
            break ;                     //「break;」の役割はswitch分を抜けること。書かないとすぐ下のブロック内の文が実行される。
        case 2 :
            printf("中吉\n") ;
            break ;
        case 3 :
            printf("吉\n") ;
            break ;
        defalut :                                 //defalutは、合致するcaseがないときに実行される
            printf("凶\n") ;                 //最後の条件には「break;」を書かない
    }
    return 0 ;
}

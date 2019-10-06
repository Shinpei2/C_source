#include <stdio.h>
#include <stdlib.h>

//文字列のメモリを確保する3つの方法

int main (void)
{
    //手段①配列宣言(スタック領域に確保)
    char array[] = "C" ;
    char* msg1 = array ;        //配列array[]の先頭アドレスをmsgl(int*型)に保持
    printf ("%s" , msg1) ;

    //手段②malloc関数を用いる(ヒープ領域への確保)
    char* msg2 = (char*)malloc(1024) ;      //msg2[1024](char型)をヒープ領域に確保
    msg2[0] = 'C' ;      //アドレスmsg2から数えて0個次のアドレスにCを格納
    msg2[1] = '\0' ;        //アドレスmsg2から数えて1個次のアドレスに終端文字
    printf ("%s",msg2) ;
    free(msg2) ;

    //手段③リテラルでメモリを確保(静的領域への確保)
    const char* msg3 = "C" ;
    printf ("%s\n",msg3) ;

    return 0 ;
}

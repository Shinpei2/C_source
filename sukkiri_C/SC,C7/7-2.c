#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    srand ((unsigned)time(0UL)) ;
    enum { Fire , Water , Wind , Earth} ;
    const char Gem_Chars[] = { '$', '*' , '@' , '#' } ;      //属性に対応した表示用の文字列を配列に格納
    int gems[10] ;

    //宝石のランダム生成
    for ( int i = 0 ; i <10 ; i++) {
        int gemType = rand()%4 ;
        gems[i] = gemType ;
    }

    //次に宝石の10個の内容を画面に表示
    for ( int i = 0 ; i < 10 ; i++){
        printf ("%c " , Gem_Chars[ gems[i] ] ) ;     //char型を文字で表す場合%cを使う。
    }

    return 0 ;
}

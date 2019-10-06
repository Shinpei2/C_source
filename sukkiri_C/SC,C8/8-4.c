#include <stdio.h>

typedef char String[1024] ;

void add (int x, int y) ;      //引数を文字列型変数nameとするhello関数をプロトタイプ宣言

int main (void)
{
    int year = 2018 ;
    add ( year , 4 ) ;
    add ( year , 50) ;
    return 0 ;
}

void add (int x, int y) {       //　関数利用者：int型の値2つを引数として渡せば和が表示される。
    int answer = x + y ;        //　関数の中身の処理は、利用者にとってどうでもいい
    printf ( "%d + %d = %d\n" , x, y , answer) ;
}

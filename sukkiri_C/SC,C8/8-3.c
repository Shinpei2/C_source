#include <stdio.h>

typedef char String[1024] ;

void hello (String name) ;      //←()の中は仮引数：「この型で引数を入力してください」


int main (void) 
{
    printf ("関数を呼び出します\n") ;
    hello ("高橋") ;      //()の中は実引数：具体的な情報
    hello ("赤城") ;
    hello ("宮津") ;
    printf ("関数の呼び出しが終了しました\n") ;
    return 0 ;
}

void hello (String name) {
    printf ("%sさん、こんにちわ。\n" , name ) ;      //引き渡された文字列を代入して関数を処理
}

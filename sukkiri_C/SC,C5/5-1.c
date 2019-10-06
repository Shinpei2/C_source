#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char String[1024] ;

int main (void)                 //コンパイルできない。変数sizeが宣言されてない。
{
    String height ;
    printf ("あなたの身長を整数値で入力してください\n") ;
    scanf ("%s" , height);
    int h = atoi (height) ;

    if ( 170 <= h ){    //if文内で宣言した変数は、if文外では消滅する。
        printf ("あなたの服のサイズはLです。\n") ;
    } else if ( h >= 160) {
        printf ("あなたの服のサイズはMです。\n") ;
    } else if ( h >= 150){
        printf ("あなたの服のサイズはSです。\n") ;
    } else {
        printf ("該当する服のサイズがありません。\n") ;
    }
    return 0 ;
}

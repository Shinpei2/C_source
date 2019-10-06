#include <stdio.h>
#include <string.h>

// memcpy , memcmp , memsetの3つの関数の使い方

int main (void)
{
    int a[4] = {19,20,29,29} ;
    int b[4] ;
    int c[4] ;
    memcpy (b,a,16) ;    //memcpy(コピー先,コピー元,サイズ)　サイズ：int型×4=16バイト
    memcpy (c,a,16) ;
    printf ("配列aの2つ目の要素は：%d、%ld番地に格納\n", a[1] , (long)&a[1]) ;
    printf ("配列bの2つ目の要素は：%d、%ld番地に格納\n\n", b[1] , (long)&b[1]) ;

    printf("配列Aの各要素：") ;
    for ( int i =0 ; i<4 ; i++ ){
        printf ("%d " , a[i] ) ;
    }
    printf("\n") ;
    printf("配列Bの各要素：") ;
    for ( int i =0 ; i<4 ; i++ ){
        printf ("%d " , *(b+i) ) ;
    }
    printf("\n\n") ;

    int r = memcmp (b,a,16 ) ;        //bのメモリ領域とaのメモリ領域を比較する。16バイト分

    //等価判定：2つのアドレス値が異なっていたとしても、2つのアドレス内の内容が等しいかどうか
    if (r == 0){
        printf("memcmpで比較した結果、等しいです。つまり等価判定の結果が真でした。\n") ;
    }
    //等値判定：同一アドレスの内容が等しいかどうか
    if ( a == b ){
        printf ("==演算子で比較した結果、等しいです。つまり等値判定の結果が真でした。\n\n") ;
    }   else{
        printf ("等値判定の結果は偽でした。\n\n") ;
    }

    printf("初期化前の配列Cの各要素：") ;
    for ( int i =0 ; i<4 ; i++ ){
        printf ("%d " , *(c+i) ) ;
    }
    printf("\n") ;

    printf("初期化前の配列Cの各要素：") ;
    memset (c,0,16) ;
    for ( int i =0 ; i<4 ; i++ ){
        printf ("%d " , *(c+i) ) ;
    }
    printf("\n") ;

    return 0 ;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sub (char* addr ){       //表示したい配列の先頭要素のポインタ変数(char*型)をください
    for (int i = 0 ; i<3 ; i++){
        printf ("%d番目：%d\n" , i+1 , *(addr+i)) ;
    }
}

int main (void)
{
    char a[] = {4,3,6} ;
    char* b = (char*)malloc(3) ;       //ポインタ型変数(char*型3バイト)をヒープ域に確保
    sub (&a[0]) ;     //表示したい配列の先頭要素のアドレスを引き渡す
    memcpy (&b[0] , &a[0],3) ;      //変えたい要素の先頭アドレスから、3バイト分
    sub (&b[0]) ;
    if ( memcmp( &b[0] , &a[0] , 3) == 0 ){
        printf ("正常にコピーされました。\n") ;
    }
    free (b);       //必ずメモリを開放する。
    return 0 ;
}

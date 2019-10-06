#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//文字列の長さを取得するstrlen関数
int main (void)
{
    //文字列の長さを取得するstrlen関数
    char str[] = "サンデーサイレンス" ;
    int len = (int)strlen(str) ;     // strlen(X)     X：文字列として確保したメモリの先頭アドレス
    printf("%d\n",len) ;

    //2つの文字列の比較をするstrcmp関数
    char str1[1024] = "hello\0ABC" ;
    const char str2[1024] = "hello\0DEF" ;
    if ( strcmp(str1,str2) == 0 ){      //文字列の長さが等しければ0を返す。
        printf ("文字列の長さが等しい\n") ;
    }   else{
        printf ("文字列の長さが異なる\n") ;
    }
    //2つの文字列の\0以前を連結させるstrcat関数
    (char*)strcat (str1, str2) ;      //注意：配列要素数を[]で指定した場合は使えない。
    printf ("%s\n" , str1) ;

    return 0 ;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
    char a [] = {49,50,51,52,53,0} ;
    char b[] = "12345" ;

    //(1)文字列の長さを表示
    printf("文字列aの長さ:%d\n", (char) strlen (&a[0]) ) ;
    printf("文字列bの長さ:%d\n", (char) strlen (&b[0]) ) ;

    //(2)文字列aとbの内容(\0までの内容)を等価判定
    if ( strcmp(a,b) == 0 ){
        printf ("aとbの文字列の長さは等しい\n") ;
    }   else {
        printf("aとbの文字列の長さは異なる。\n") ;
    }

    //(3)aとbを連結するためのポインタ変数cを宣言(ヒープ領域に保存)
    char* c = (char*)malloc( strlen(a) + strlen(b) + 1 ) ;

    //(4)cにaとbを連結したものを格納
    strcpy(c,a) ;
    strcat(c,b) ;
    printf("文字列cの内容:%s\n", c) ;       //一応表示

    //(5)cで確保した領域を解放
    free(c) ;

    return 0 ;
}

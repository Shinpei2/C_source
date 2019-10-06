#include <stdio.h>

void funkA (void) ;             //プロトタイプ型の宣言　→main関数を先に書ける。
void funkB (void) ;

int main (void)         //コンパイルはmain関数からスタートする。
{
    funkA () ;
    return 0 ;
}

void funkA (void)       //
{
    printf ("関数Aです\n") ;
    funkB () ;
}

void funkB (void)       //　関数の宣言＝戻り値 関数名　(引数)｛ 処理 ｝
{
    printf ("関数Bです\n") ;
}

#include <stdio.h>

void funkB (void)       //　関数の宣言＝戻り値 関数名　(引数)｛ 処理 ｝
{
    printf ("関数Bです\n") ;
}

void funkA (void)       //仮引数のない関数は、必ず()の中にvoidを明記すること
{
    funkB () ;
    printf ("関数Aです\n") ;
}

int main (void)         //プロトタイプ宣言しないと、main関数が下側に持ってこないといけない
{
    funkA () ;
    printf ("関数の呼び出しが終わりました\n") ;
    return 0 ;
}

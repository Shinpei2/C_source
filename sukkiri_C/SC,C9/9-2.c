#include <stdio.h>

int main (void)
{
    int a = 70 ;
    printf ("変数aには%dが入っています\n" , a ) ;

    int* addrA = (int*) &a ;       //saddrAの先頭から4バイトを保持したポインタ型変数
    printf ("変数aのアドレス：%p\n" , addrA ) ;
    printf ("%p番地に格納されている情報:%d" , addrA , *addrA ) ;// 「* P型変数」→アドレス上のデータ


    return 0 ;
}

#include <stdio.h>

int main (void)
{
    int a = 70 ;
    printf ("変数aには%dが入っています\n" , a ) ;

    void* addressA = (void*) &a ;       //(型)→型変換
    printf ("void*型の変数aのアドレス：%p\n" , addressA ) ;       //数字の羅列ではなくなる
    long addrA = (long) &a ;       //(型)→型変換
    printf ("long型の変数aのアドレス：%ld\n" , addrA ) ;
    return 0 ;
}

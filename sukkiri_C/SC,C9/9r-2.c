#include <stdio.h>

int main (void)
{
    char moji ;
    int money ;
    char *mojiAddr = &moji ;            //mojiのアドレスを保持する変数を宣言
    int *moneyAddr = &money ;       //moneyのアドレスを保持する変数を宣言

    printf("mojiの消費メモリ量：%dバイト\n" , (char)sizeof(moji) ) ;
    printf("moneyの消費メモリ量：%dバイト\n" , (int)sizeof(money) ) ;
    printf("mojiAddrの消費メモリ量：%pバイト\n" , (char*)sizeof(mojiAddr) ) ;
    printf("moneyAddrの消費メモリ量：%pバイト\n" , (int*)sizeof(moneyAddr) ) ;
    return 0 ;
}

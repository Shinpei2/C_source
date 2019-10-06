#include <stdio.h>

int add (int x , int y) ;

int main (void)
{
    int year = 2018 ;
    int ans1 ;                       //戻り値を保存する変数を用意する。
    ans1 = add (year , 4) ;
    printf ("%d年の%d年後は%dねんです\n" , year , 4 , ans1) ;

    int ans2 ;
    ans2 = add (year , 50) ;
    printf ("%d年は%d年の%d年後です" , ans2 , year , 50 ) ;
    return 0  ;     //main関数の最後の行は、「OSに対して0を返す処理」→終了コードという
}

int add (int x , int y)
{
    int ans = x + y ;
    return ans ;        //戻り値がある場合は、returnで返す。
}

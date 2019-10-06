#include <stdio.h>
#include <stdlib.h>     //「文字列→整数」に必要

typedef char String[1024] ;   //文字型の宣言が必要

int main (void)
{
  int age = 29 ;
  String name = "かいとう" ;
  String kazu = "122" ;
  printf ("こんにちは。%s回目の登場です。\n" , kazu) ;
  printf ( "私は%d歳の%sです。\n", age, name) ;
  int n = atoi (kazu) ;       //文字型をint型に変換する。int 新規変数 = atoi (文字型変数)
  printf ("今、文字型の\"122\"を、整数型の%dに変換しました。" , n) ;
  return 0 ;
}

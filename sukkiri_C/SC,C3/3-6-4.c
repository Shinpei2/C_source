#include <stdio.h>    //printf、schanfの呼び出しに必要
#include <stdlib.h>

typedef char String[1024] ;

int main (void)
{
      String name ;
      printf ( "あなたの名前を入力してください。\n" ) ;
      scanf ( "%s" , name ) ;    //キーボードからの1行分の文字列を受け付ける

      String ageStr ;
      printf ( "あなたの年齢を入力してください。\n" ) ;
      scanf ( "%s" , ageStr ) ;

      int age = atoi (ageStr) ;
      printf ("ようこそ、%d歳の%sさん" , age , name ) ;
      return 0 ;
  }

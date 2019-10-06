#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char String[1024] ;

int main (void)
{
    printf ("***数当てゲーム(レベル1)***\n") ;
    printf ("回答のチャンスは4回までです\n") ;
    printf ("1行の数(0~9のどれか)を入力してください：\n") ;
    srand ( (unsigned) time (0UL) ) ;
    int answer = rand()%10 ;
    String inputNo ;
    int input ;

    for ( int i = 1 ; i <= 4 ; i++  ){
        scanf ("%s" , inputNo ) ;
        input = atoi (inputNo) ;
        if ( input == answer ){
            printf ("正解です!\n%d回目で正解\n" , i  ) ;
            break ;         //breakを入れることでループを抜けられる
        }   else if ( input < answer) {
                printf ("はずれです！答えはもっと大きな数です。\n") ;
        }   else {
                printf ("はずれです！答えはもっと小さな数です。\n") ;
        }
    }
    if ( input != answer ) {
        printf("答えは%dでした\n" , answer ) ;
    }
    return 0 ;
}

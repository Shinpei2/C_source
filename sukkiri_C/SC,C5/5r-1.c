#include <stdio.h>
#include <stdlib.h>

typedef char String[1024] ;

int main (void)
{
    String Point ;
    printf ("あなたのポイントを入力してください。\n") ;
    printf ("※0以上の整数値で入力してください。\n") ;
    scanf ("%s" , Point) ;
    int P = atoi (Point) ;
    printf ("あなたのポイントは%dポイントです。\n" , P ) ;

    if ( P >= 100){
        printf ("現在のポイントを旅行券と交換できます\n") ;
    }   else if (P >= 50){
            printf ("現在のポイントを買い物券と交換できます\n") ;
    }   else if (P >= 10){
            printf ("現在のポイントを割引券と交換できます\n") ;
    }   else {
            printf ("現在のポイントをあめ玉券と交換できます\n") ;
    }
    return 0 ;
}

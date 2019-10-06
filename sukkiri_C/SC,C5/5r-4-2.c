#include <stdio.h>
#include <stdlib.h>

typedef char String[1024] ;

int main (void)
{
    String Otoshidama;
    String Kudamono ;

    printf ("お年玉の金額を入力してください。\n") ;
    scanf ("%s" , Otoshidama) ;
    int O = atoi (Otoshidama) ;
    printf ("果物の種類を番号で選んでください\nリンゴ：1　ミカン：2\n") ;
    scanf ("%s" , Kudamono) ;
    int K = atoi (Kudamono) ;

    int SetPrice ;
    switch ( K ){
        case 1 :
            SetPrice = 120 ;        //リンゴのセットあたり(1個)の値段
            break ;
        case 2 :
            SetPrice = 400 ;        //ミカンのセットあたりの値段
            break ;
        default :
            printf ("該当する果物はありません\n") ;
    }
        printf ("セット価格は%d円\n" , SetPrice ) ;

    int Set = 0 ;
    int Amari = 0 ;
    int Kosu ;
    if (K ==1 || K == 2 ){
        while ( O >= SetPrice  ) {
            O -=  SetPrice ;
            Set++ ;
        }
        if (K ==1){
            Kosu = Set ;
        }   else{
            Kosu = Set*6 ;
        }
        printf("あなたが選んだ果物は最大%d個買え、余りは%d円です。\n", Kosu , O ) ;
    }


    return 0 ;
}

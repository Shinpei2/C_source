#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main (void)
{
    for (int i = 1 ; i < 10 ; i++ ) {
        if ( i ==3 ){               //iが3の場合のみを除いて、継続
            continue ;
        }
        for (int j =1 ; j < 10 ; j++) {
            if ( j == 8 ){          //jが8になったら、jのループを抜ける。
                break ;
            }
            printf ("%d　" , i*j ) ;
        }
        printf ("\n") ;             //3の段および各段の8,9番目の数が抜けたものが出来る。
    }
    return 0 ;
}

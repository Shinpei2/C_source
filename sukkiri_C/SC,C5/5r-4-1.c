#include <stdio.h>

typedef char String[1024] ;

int main (void)
{
    const int Otoshidama = 3000 ;
    int pocket = Otoshidama ;

    printf("リンゴ") ;
    while ( pocket >= 120 ) {
        pocket -= 120 ;
        printf ("*") ;
    }
    printf ("　余りは%d円\n" , pocket ) ;

    pocket = Otoshidama ;
    printf("ミカン") ;
    while ( pocket >= 400 ) {        //ミカンの個数を数える
        pocket -= 400 ;
        printf ("******") ;
    }
    printf ("　余りは%d円\n" , pocket ) ;
    return 0 ;
}

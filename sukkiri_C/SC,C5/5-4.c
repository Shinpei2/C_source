#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    enum {Daikichi = 1 , Chukichi , Kichi , Kyo } ;

    printf ("あなたの今日の運勢を占います\n") ;
    srand ( (unsigned) time (0UL) ) ;
    int fortune = rand()%4 +1 ;

    switch (fortune) {
        case Daikichi :
            printf("大吉\n") ;
            break ;
        case Chukichi :
            printf ("中吉\n") ;
            break ;
        case Kichi :
            printf ("吉\n") ;
            break ;
        default :
            printf ("凶\n") ;
    }
    return 0 ;
}

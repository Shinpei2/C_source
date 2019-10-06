#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    printf ("4桁の暗証番号を生成します\n") ;
    srand((unsigned)time(0UL)) ;
    int r1 = rand () % 10 ;     //
    int r2 = rand () % 10 ;
    int r3 = rand () % 10 ;
    int r4 = rand () % 10 ;
    printf ("暗証番号：%d%d%d%d\n" , r1, r2, r3, r4 ) ;
    return 0 ;
}

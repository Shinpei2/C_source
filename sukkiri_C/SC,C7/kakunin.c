#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef char str[1024] ;

int main (void)
{
    int Con ;
    str ConNo ;
    printf ("続けますか?(1:続ける 2:終了)\n") ;
    scanf ("%s" , ConNo ) ;
    Con = atoi ( ConNo ) ;
    return 0 ;
}

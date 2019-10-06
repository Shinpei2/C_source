#include <stdio.h>

int main (void)
{
    int a = 5 ;
    int b = 6 ;
    int c = 7 ;
    int d = 8 ;
    int e = 10 ;
    a += b ;      // a+b →a 　※a = 11
    b -= a ;      //  b-a  →b　※b = -5
    c *= b ;    // c*b → c　※c = -35
    e /= b ;    // e/b → e　※ e = -2
    d %= a; //　※ d = 8
    printf("%d\n" , a) ;
    printf("%d\n" , b) ;
    printf("%d\n" , c) ;
    printf("%d\n" , e) ;
    printf("%d\n" , d) ;
    return 0 ;
}

#include <stdio.h>

int main (void)
{
    float a ;
    float b ;
    float c ;
    a = 9 / 2 ;
    b = 9.0 / 2 ;
    c = 9 / 2 ;
    printf ( "%f\n" , a ) ;       //float型の表示→%f
    printf ( "%f\n" , b ) ;
    printf ( "%f\n" , c ) ;        //double型の表示→%f
    return 0 ;
}

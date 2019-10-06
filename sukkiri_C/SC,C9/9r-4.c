#include <stdio.h>

void funkB (void){
    int b = 20 ;
    printf ("b-address：%ld\n" , (long)&b) ;
}

void funkA (void){
    int a = 10 ;
    printf ("a-address：%ld\n" , (long)&a) ;
    funkB () ;
}
int main (void)
{
    funkA () ;
    return 0 ;
}

#include <stdio.h>      //←printfの読み出しに用いる

int main (void)
{
        int age = 29 ;
        printf ( "今年で%d歳で、" , age ) ;
        int newAge = age + 1 ;
        printf ( "今年は%dですね\n" , newAge ) ;
        float pi = 3.1415 ;
        printf ("%5f" , 3.1415 ) ; 
        return 0 ;
}

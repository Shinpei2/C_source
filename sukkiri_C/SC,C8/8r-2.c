#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char String[1024] ;
bool isLeapYear (int year) ;

int main (void)
{
    String thisyear ;
    printf ("西暦を入力してください。\n") ;
    scanf ("%s" , thisyear ) ;
    int ty = atoi (thisyear) ;

    if ( isLeapYear( ty ) ){
        printf ("今年は閏年です\n") ;
    }    else{
            printf("今年は閏年ではありません\n") ;
    }
    return 0 ;
}

bool isLeapYear (int year)
{
    return ( year%400 == 0 || (year%4 == 0 && year%100 != 0) ) ;
}

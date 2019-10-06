#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    printf("いただきます\nバナナを食べます\n") ;

    bool more = false ;
    if ( more == true ){
        printf("おかわりをください\n") ;
    }   else{
            printf("お腹がいっぱいです\n") ;
    }
    printf("ごちそうさまでした\n") ;
    return 0 ;
}

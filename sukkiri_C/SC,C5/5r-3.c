#include <stdio.h>
#include <stdlib.h>

typedef char String[1024] ;

int main (void)
{
    String Position ;
    printf ("1~9の数を入力してください\n") ;
    scanf ("%s", Position ) ;
    int P = atoi (Position) ;
    switch (P){
        case 1 : case 2 :
            printf ("バッテリー\n") ;
            break ;
        case 3 : case 4 : case 5 : case 6 :         //複数条件を1行に纏めてもOK
            printf ("内野手\n") ;
            break ;
        case 7 : case 8 : case 9 :
            printf ("外野手\n") ;
            break ;
        default :
            printf ("入力された守備位置はありません\n") ;
    }
    return 0 ;
}

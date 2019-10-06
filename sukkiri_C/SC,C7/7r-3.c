#include <stdio.h>

int main (void)
{
    typedef struct {
        int code ;
        char character ;
    } Ascii ;
    Ascii characters[26] ;
    printf ("***大文字アルファベットA~Zに対応するASCllコード***\n") ;
    for ( int i =0 ; i<26 ; i++ ){
        characters[i].code = i+65 ;          //A~ZのASCllコード = 65~90
        characters[i].character = i + 65 ;
        printf ("%d:%c　" ,characters[i].code, characters[i].character ) ;
    }
    return 0 ;
}

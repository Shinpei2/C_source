#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (void)
{
    char str[1024] ;
    scanf ( "%s", str );
    printf ("文字列の大きさ：%d", (int)strlen(str)) ;
    return 0 ;
}

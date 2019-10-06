#include <stdio.h>

void printIntByAddress (int *addr){
    printf ("変数が保持さているアドレス：%ld\n" , (long)addr) ;
    printf ("変数に格納されている値：%d\n" , *addr) ;
}
int main (void)
{
    int a = 80 ;
    printIntByAddress (&a) ;
    return 0 ;
}

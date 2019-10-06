#include <stdio.h>

int main (void)
{
    for ( int i = 0; i < 10 ; i++ ) {          //初期値0、条件：i<10、増分1、にすれば10回
        printf ("いらっしゃいませ、こんにちわ。") ;
        printf ("今%d回目です。\n" , i +1) ;
    }
    return 0 ;
}

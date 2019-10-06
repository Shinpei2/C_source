#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool tenki = false ;
    if (tenki == true){     //もしtenkiがrtueの場合、=2つである点に注意
        printf("選択をします\n") ;
        printf("散歩に行きます\n") ;
    } else{                     //そうでない場合は
        printf("映画を見ます\n") ;
    }
    return 0 ;
}

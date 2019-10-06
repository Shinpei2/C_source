#include <stdio.h>
#include <stdbool.h>        //boolを用いるのに必要

int main(void)
{
    bool doorClosed = true ;        //trueを入れると無限に繰り返し。Ctrl＋Cで強制終了
    while(doorClosed == true){
        printf("ノックする\n") ;
        printf("1分待つ\n") ;      //終了条件を入れないと、無限に処理が繰り返し
    }
    return 0 ;
}

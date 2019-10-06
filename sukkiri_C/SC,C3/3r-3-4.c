#include <stdio.h>
#include <stdlib.h>

typedef char String[1024] ;

int main (void)
{
    String sumStr ;
    printf ("カレンダーから縦に並んだ数字を3つ選び、その合計を入力してださい\n") ;
    scanf ("%s" , sumStr ) ;

    int sum = atoi (sumStr) / 3 ;       //文字型変換と同時に計算もできる。
    printf ("選んだ数字は%dと%dと%dですね？\n" , sum - 7, sum, sum +7 ) ;       //←X,Y,Zを変数指定しなくても行ける。
    return 0 ;
}

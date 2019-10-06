#include <stdio.h>

int main (void)
{
        float f = 3 ;           //float型の変数にint型の値を代入
        double d = f ;          //double型の変数にfloat型の値を代入
        int age = (int) 3.1415 ;         //(変換先の型名)式で型変換
        printf("%f，", f ) ;
        printf("%f，" , d ) ;
        printf("%d\n" , age ) ;
        return 0 ;
}

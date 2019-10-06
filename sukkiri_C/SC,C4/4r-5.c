#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char String[1024] ;

int main (void)
{
    int temp = 30 ;
    int ansNo =1 ;      //
    String answer ;
    while ( ansNo ==1 ){        //while文の条件式中のイコール関係は==で表す。
        printf ("現在の設定温度：%d\n" , temp) ;
        printf ("暑いですか?　Yes=1　No=0\n") ;
        scanf ("%s" , answer ) ;        //scanfは文字型を入力させる
        ansNo = atoi (answer) ;     //入力した値を数字に変換
        if ( ansNo == 1){       //1の場合は継続、0の場合はループを抜ける分岐
            temp -= 1 ;
        }   else{
            printf("設定を終了します\n") ;
        }
    }
    return 0 ;
}

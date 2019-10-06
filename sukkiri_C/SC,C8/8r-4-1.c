#include <stdio.h>
#include <stdlib.h>
//***ルール***
//1人あたりの支払額は、支払総額を参加人数で割った金額
//支払い単位は100円、100円未満の金額は切り上げ
//支払総額を超過した分は、幹事が受け取る

typedef char String[1024] ;

int main (void)
{
    int amount ;        //支払総額
    int people ;        //参加人数
    int pay ;           //1人あたりの支払総額
    int payorg ;        //幹事の支払総額

    String inputStr ;       //キー入力を格納するための文字列型変数
    double dnum ;

    // 計算データの入力
    printf ("支払総額を入力してください：") ;
    scanf ("%s" , inputStr ) ;
    amount = atoi (inputStr) ;

    printf ("参加人数を入力してください：") ;
    scanf ("%s" , inputStr ) ;
    people = atoi (inputStr) ;

    // 割り勘額(幹事以外)の計算
    dnum = (double)amount / people ;      //総額を人数で割る(端数も保持)
    pay = (int)(dnum/100) * 100 ;            // dnum/100をint型にすることで、100円未満を切り捨て
    if ( dnum > pay ){                              //元の割り勘額と切り捨て後の額を比較
        pay += 100 ;
    }

    //幹事の支払額の計算
    payorg = amount - pay * (people - 1) ;

    //結果の表示
    printf ( "***支払額***\n" ) ;
    printf ("1人あたり%d円 (%d人)、幹事は%d円です。\n" , pay , people-1, payorg ) ;

    return 0 ;
}

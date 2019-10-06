#include <stdio.h>
#include <stdlib.h>

int iscanf (void) ;
int calcPayment ( int dividend , int divisor ) ;
void showPayment ( int general, int host , int numbers ) ;

typedef char String[1024] ;

int main (void)
{
    int amount ;        //支払総額
    int people ;        //参加人数
    int pay ;           //1人あたりの支払総額
    int payorg ;        //幹事の支払総額

    // 計算データの入力
    printf ("支払総額を入力してください：") ;
    amount = iscanf () ;
    printf ("参加人数を入力してください：") ;
    people = iscanf () ;

    // 割り勘額(幹事以外)の計算
    pay = calcPayment ( amount , people ) ;

    //幹事の支払額の計算
    payorg = amount - pay * (people - 1) ;

    //結果の表示
    showPayment ( pay , payorg , people ) ;

    return 0 ;
}

int iscanf (void){
    String inputStr ;       //キー入力を格納するための文字列型変数
    scanf ("%s" , inputStr ) ;
    return atoi (inputStr) ;
}

int calcPayment ( int dividend , int divisor )
{

    double dnum = (double)dividend / divisor ;      //総額を人数で割る(端数も保持)
    int person = (int)(dnum/100) * 100 ;            // dnum/100をint型にすることで、100円未満を切り捨て
    if ( dnum > person ){                              //元の割り勘額と切り捨て後の額を比較
        person += 100 ;
    }
    return person ;
}

void showPayment ( int general, int host , int numbers )
{
    printf ( "***支払額***\n" ) ;
    printf ("1人あたり%d円 (%d人)、幹事は%d円です。\n" , general , numbers-1, host ) ;
}

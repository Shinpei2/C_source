#include <stdio.h>
#include <stdlib.h>

typedef char String[1024] ;

typedef struct {
    String name ;
    int hp ;
    int attack ;
} Monster ;

void printMonsterSummary ( Monster* m) ;

int main (void)
{

    Monster seiryu = {"青龍" , 80 , 15 } ;        //構造体変数宣言+初期化
    Monster suzaku = {"朱雀" , 100 , 30 } ;
    Monster byakko = {"白虎" , 100 , 20 } ;
    Monster genbu = {"玄武" , 120 , 10 } ;

    printMonsterSummary (&seiryu) ;     // suzakuのアドレスを引数として渡す。
    printMonsterSummary (&suzaku) ;
    printMonsterSummary (&byakko) ;
    printMonsterSummary (&genbu) ;

    return 0 ;
}

//モンスターのHPと攻撃力を返す関数
void printMonsterSummary ( Monster* m ) {     //仮引数：Monster型の構造体変数のアドレス
    printf ("モンスター %s ( HP= %d)\n" , (*m).name , m->hp ) ;
}

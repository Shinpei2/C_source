#include <stdio.h>

typedef char String[1024] ;

int main (void)
{
    typedef struct{ String name ; int hp ; int attack; } Monster ;

    Monster seiryu = {"青龍" , 80 , 15 } ;
    Monster suzaku = {"朱雀" , 100 , 30 } ;
    Monster byakko = {"白虎" , 100 , 20 } ;
    Monster genbu = {"玄武" , 120 , 10 } ;

    Monster monster[ ] = {suzaku , genbu, seiryu, byakko } ;        //  Monster型の配列、monster[]を生成。

    const String Template = "%s : HP = %3d , 攻撃力 = %2d\n" ;
    for ( int i = 0 ; i < 4 ; i++){
        printf ( Template, monster[i].name , monster[i].hp , monster[i].attack ) ;        //構造体変数.メンバ
    }
    return 0;
}

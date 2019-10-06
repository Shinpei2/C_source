#include <stdio.h>

typedef char String[1024] ;

int main (void)
{
    typedef struct {        //  構造体型の型struct{…}を、新たな型Monsterに定義付け
        String name ;
        int hp ;
        int attack ;
    } Monster ;

    Monster seiryu = {"青龍" , 80 , 15 } ;        //構造体変数宣言+初期化
    Monster suzaku = {"朱雀" , 100 , 30 } ;
    Monster byakko = {"白虎" , 100 , 20 } ;
    Monster genbu = {"玄武" , 120 , 10 } ;

    const String TEMPLATE = "%s ： HP=%3d　攻撃力=%2d\n" ;       //この行の役割は？
    printf ( TEMPLATE , seiryu.name , seiryu.hp , seiryu.attack ) ;
    printf ( TEMPLATE , suzaku.name , suzaku.hp , suzaku.attack ) ;
    printf ( TEMPLATE , byakko.name , byakko.hp , byakko.attack ) ;
    printf ( TEMPLATE , genbu.name , genbu.hp , genbu.attack ) ;

    return 0 ;
}

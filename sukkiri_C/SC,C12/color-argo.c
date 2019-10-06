#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//属性値等の定義
char symbols[6] = {'$','~','@','#','&',' '} ;
int ColorNumber[6] = {1,6,2,3,5,0} ;      //赤、水色、緑、黄、紫、黒が対応

//列挙型の定義
typedef enum Element { FIRE , WATER , WIND ,EARTH , LIFE , EMPTY} Element ;

//構造体型の宣言
typedef struct {char* name ; int HP ; int maxHP ; Element element ; int attack ; int gard; } Monster ;

//プロトタイプ宣言
void printMonsterName (Monster* monsterInfo) ;

int main (void) {
    Monster slime = {"スライム",100,100, WATER ,10,  5} ;
    Monster goblin = {"ゴブリン",200,200, EARTH ,20,15} ;
    Monster bigCombat = {"オオコウモリ",300,300, WIND ,30,25} ;
    Monster wearWolf= {"ウェアウルフ",400,400,WIND,40,40} ;
    Monster Dragon = {"ドラゴン",800,800,FIRE,50,40} ;

    printMonsterName (&slime) ;
    printMonsterName (&goblin) ;
    printMonsterName (&bigCombat) ;
    printMonsterName (&wearWolf) ;
    printMonsterName (&Dragon) ;

    return 0;
}

//モンスター名に色と記号をつける関数
void printMonsterName (Monster* monsterInfo){
    printf ("\n受け取ったモンスターの属性番号：%d\n", (*monsterInfo).element) ;
    char symbol ;
    int color ;     //モンスターの属性に応じた色を格納する変数
    for (int i = 0 ; i<6 ; i++){
        if( (*monsterInfo).element == i){
                symbol = symbols[i] ;
                color = ColorNumber[i] ;
        }
    }
    printf("\x1b[3%dm", color) ;
    printf("%c%s%c", symbol, (*monsterInfo).name, symbol) ;
    printf("\x1b[0m") ;
    return ;
}

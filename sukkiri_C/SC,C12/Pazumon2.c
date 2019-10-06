/*=== puzumon:0 ソースコードひな形===*/
/*** インクルード宣言 ***/

#include <stdio.h>
#include <string.h>

/*** 列挙型宣言 ***/
typedef enum Element { FIRE , WATER , WIND ,EARTH , LIFE , EMPTY} Element ;     //各属性値：0~5が対応

/*** グローバル定数の宣言 ***/
char symbols[6] = {'$','~','@','#','&',' '} ;
int ColorNumber[6] = {1,6,2,3,5,0} ;      //赤、水色、緑、黄、紫、黒が対応

/*** 構造体型宣言 ***/
//モンスター情報
typedef struct {
    char* name ;
    int HP ;
    int maxHP ;
    Element element ;
    int attack ;
    int gard;
} Monster ;

//ダンジョン情報
typedef struct DUNGEON {
  Monster* monsters;
  const int numMonsters;
} Dungeon;


/*** プロトタイプ宣言 ***/
int goDungeon (char* playerName, Dungeon* playDungeon) ;        //ダンジョン全体に責任を持つ関数
int doBattle (char* player ,Monster* monster) ;            //1回のバトル開始から終了までの流れに責任を持つ関数

/*** ユーティリティ宣言 ***/
void  printMonsterName (Monster* monsterInfo) ;    //モンスターの色付け


//ゲーム開始から終了まで
int main (int argc, char** argv)
{
    //敵モンスターの基本情報　→Mosnster型の配列にする。
    Monster slime = {"スライム",100,100, WATER ,10,  5} ;
    Monster goblin = {"ゴブリン",200,200, EARTH ,20,15} ;
    Monster bigCombat = {"オオコウモリ",300,300, WIND ,30,25} ;
    Monster wearWolf= {"ウェアウルフ",400,400,WIND,40,40} ;
    Monster Dragon = {"ドラゴン",800,800,FIRE,50,40} ;
    Monster DungeonMonster1[] ={slime,goblin,bigCombat,wearWolf,Dragon};
    Dungeon dungeon1 = {DungeonMonster1 , 5} ;   //DungeonMonster1は配列先頭要素のアドレスを示す。


    if (argc != 2){
        printf("エラー：プレイヤー名を指定して起動してください\n") ;
        return 0;
    }   else {                                                         //正しく名前が入力されたら、ゲームスタート
        printf("*** Puzzle & Monsters ***\n") ;

        char* pName = "player" ;      //ダミー。現時点ではargvの渡し方がわからない
        int Victory = goDungeon(pName, &dungeon1) ;

        if (Victory == dungeon1.numMonsters) {
            printf("*** GAME CLEARED! ***\n") ;
            printf("倒したモンスター数=%d", Victory) ;
        }   else {
            printf("*** GAME OVER ***\n") ;
            printf("倒したモンスター数=%d", Victory) ;
        }
    }
    return 0 ;
}


/*** 関数宣言 ***/
int goDungeon (char* playerName, Dungeon* playDungeon){       //Dungeon配列には「DungeonMonsterとモンスター数が格納されている」
    printf("%sはダンジョンに到着した\n" , playerName) ;
    int knockCount = 0 ;
    for (int i = 0 ; i < (*playDungeon).numMonsters ; i+=1){
        knockCount += doBattle (playerName,&(playDungeon->monsters[i])) ;       //ダンジョン内モンスターのアドレス
        //printf("knockCountのカウント：%d\n", knockCount ) ;
        if ( knockCount == i) {
            printf ("%sはダンジョンから逃げ出した\n", playerName) ;
            return knockCount;
        }   else if ( knockCount == 5){
                printf("%sはダンジョンを制覇した\n", playerName) ;
                return knockCount ;
        }   else {
                printf("%sは更に奥に進んだ\n", playerName) ;
        }
    }
}

int doBattle (char* player ,Monster* monster){      //勝ったら１，負けたら0を返す
    printMonsterName(monster) ;
    printf("が現れた!\n") ;
    int win =1 ;
    //printf("勝ちなら1,負けなら0\n入力：") ; scanf("%d", &win ) ;    //←ダミー。勝ち負けをキーボード入力。

    if (win == 1) {
        printMonsterName(monster) ;
        printf("を倒した！\n") ;
        return 1;
    }   else {
            return 0;
    }
    return 0;
}

//モンスター名に色と記号をつける関数
void printMonsterName (Monster* monsterInfo){
    //printf ("\n受け取ったモンスターの属性番号：%d\n", (*monsterInfo).element) ;
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
